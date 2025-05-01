#include "UserManager.h"
#include <fstream>
#include <sstream>

using namespace System;
using namespace System::Collections::Generic;

List<User^>^ UserManager::readUsersFromFile(String^ filename) {
    List<User^>^ users = gcnew List<User^>();

    std::ifstream fin(msclr::interop::marshal_as<std::string>(filename));

    std::string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string fullname, password, role;

        std::getline(ss, fullname, '|');
        std::getline(ss, password, '|');
        std::getline(ss, role, '|');

        User^ user = gcnew User();
        user->fullname = gcnew String(fullname.c_str());
        user->fullname = user->fullname->Trim();

        user->password = gcnew String(password.c_str());
        user->password = user->password->Trim();

        user->role = gcnew String(role.c_str());
        user->role = user->role->Trim();


        users->Add(user);
    }

    fin.close();
    return users;
}

bool UserManager::addUser(String^ fullname, String^ role, String^ password, String^ filename) {
    std::string nativeFullname = msclr::interop::marshal_as<std::string>(fullname->Trim());
    std::string nativeRole = msclr::interop::marshal_as<std::string>(role->Trim());
    std::string nativePassword = msclr::interop::marshal_as<std::string>(password->Trim());
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());

    std::ofstream outFile(nativeFilename, std::ios::app);

    if (outFile.is_open()) {
        outFile << nativeFullname << " | " << nativePassword << " | " << nativeRole << std::endl;
        outFile.close();
        return true;
    }
    else {
        return false;
    }
}

bool UserManager::editUser(String^ oldFullname, String^ fullname, String^ role, String^ password, String^ filename) {
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());
    std::string nativeOldFullname = msclr::interop::marshal_as<std::string>(oldFullname->Trim());

    std::string nativeFullname = msclr::interop::marshal_as<std::string>(fullname->Trim());
    std::string nativePassword = msclr::interop::marshal_as<std::string>(password->Trim());
    std::string nativeRole = msclr::interop::marshal_as<std::string>(role->Trim());

    std::ofstream outFile(nativeFilename, std::ios::app);

    std::ifstream fin(nativeFilename);
    std::vector<std::string> lines;
    std::string line;

    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    bool userFound = false;

    for (int i = 0; i < lines.size(); i++) {
        std::istringstream ss(lines[i]);
        std::string existingFullname, existingPassword, existingRole;

        std::getline(ss, existingFullname, '|');
        std::getline(ss, existingPassword, '|');
        std::getline(ss, existingRole, '|');

        existingFullname.erase(0, existingFullname.find_first_not_of(" \t\n\r"));
        existingFullname.erase(existingFullname.find_last_not_of(" \t\n\r") + 1);

        if (existingFullname == nativeOldFullname) {
            lines[i] = nativeFullname + " | " + nativePassword + " | " + nativeRole;
            userFound = true;
            break;
        }
    }

    if (userFound) {
        std::ofstream outFile(nativeFilename, std::ios::trunc);
        for (const auto& line : lines) {
            outFile << line << std::endl;
        }
        outFile.close();
        return true;
    }
    else {
        return false;
    }
}

bool UserManager::deleteUser(String^ fullname, String^ filename) {
    std::string nativeFullname = msclr::interop::marshal_as<std::string>(fullname->Trim());
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());

    std::ifstream fin(nativeFilename);
    std::vector<std::string> lines;
    std::string line;

    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::string fullname, password, role;

        std::getline(ss, fullname, '|');
        fullname.erase(0, fullname.find_first_not_of(" \t\n\r"));
        fullname.erase(fullname.find_last_not_of(" \t\n\r") + 1);

        if (fullname == nativeFullname) {
            continue;
        }

        lines.push_back(line);
    }

    fin.close();

    std::ofstream fout(nativeFilename, std::ios::trunc);

    if (!fout.is_open()) return false;

    for (const auto& l : lines) {
        fout << l << "\n";
    }

    fout.close();
    return true;
}