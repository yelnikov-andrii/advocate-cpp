#include "ClientManager.h"
#include <fstream>
#include <sstream>

using namespace System;
using namespace System::Collections::Generic;

List<Client^>^ ClientManager::readClientsFromFile(String^ fullnameOfCurrentAdvocate, String^ filename) {
    List<Client^>^ clients = gcnew List<Client^>();

    std::ifstream fin(msclr::interop::marshal_as<std::string>(filename));

    std::string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string id, advocateFullname, fullname, phone, email;

        std::getline(ss, id, '|');
        std::getline(ss, advocateFullname, '|');
        std::getline(ss, fullname, '|');
        std::getline(ss, phone, '|');
        std::getline(ss, email, '|');

        Client^ client = gcnew Client();
        client->id = gcnew String(id.c_str());
        client->id = client->id->Trim();

        client->advocateFullname = gcnew String(advocateFullname.c_str());
        client->advocateFullname = client->advocateFullname->Trim();

        client->fullname = gcnew String(fullname.c_str());
        client->fullname = client->fullname->Trim();

        client->phone = gcnew String(phone.c_str());
        client->phone = client->phone->Trim();

        client->email = gcnew String(email.c_str());
        client->email = client->email->Trim();

        String^ nativeAdvocateFullname = gcnew String(advocateFullname.c_str());
        nativeAdvocateFullname = nativeAdvocateFullname->Trim();

        if (fullnameOfCurrentAdvocate == nullptr || fullnameOfCurrentAdvocate == "") {
            clients->Add(client);
        }

        if (nativeAdvocateFullname == fullnameOfCurrentAdvocate) {
            clients->Add(client);
        }
    }

    fin.close();
    return clients;
}

bool ClientManager::addClient(String^ advocateFullname, String^ fullname, String^ phone, String^ email, String^ filename) {
    std::string nativeAdvocateFullname = msclr::interop::marshal_as<std::string>(advocateFullname->Trim());
    std::string nativeFullname = msclr::interop::marshal_as<std::string>(fullname->Trim());
    std::string nativePhone = msclr::interop::marshal_as<std::string>(phone->Trim());
    std::string nativeEmail = msclr::interop::marshal_as<std::string>(email->Trim());
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());
    std::ofstream idFile("clientLastId.txt", std::ios::app);

    int clientId = 0;
    std::ifstream idIn("clientLastId.txt");

    if (idIn.is_open()) {
        idIn >> clientId;
        idIn.close();
    }
    clientId++;

    std::ofstream outFile(nativeFilename, std::ios::app);
    if (!outFile.is_open()) return false;

    outFile << clientId << " | " << nativeAdvocateFullname << " | " << nativeFullname << " | "
        << nativePhone << " | " << nativeEmail << std::endl;
    outFile.close();

    std::ofstream idOut("clientLastId.txt", std::ios::trunc);
    if (idOut.is_open()) {
        idOut << clientId;
        idOut.close();
    }

    return true;
}

Client^ ClientManager::getOne(String^ id, String^ filename) {
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());

    std::ifstream file(nativeFilename);
    if (!file.is_open()) return nullptr;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string clientId, advocateFullname, fullname, phone, email;

        std::getline(ss, clientId, '|');
        std::getline(ss, advocateFullname, '|');
        std::getline(ss, fullname, '|');
        std::getline(ss, phone, '|');
        std::getline(ss, email, '|');

        String^ clientIdStr = gcnew String(clientId.c_str());
        clientIdStr = clientIdStr->Trim();

        if (clientIdStr == id) {
            Client^ c = gcnew Client();
            c->id = gcnew String(clientId.c_str());
            c->id = c->id->Trim();

            c->advocateFullname = gcnew String(advocateFullname.c_str());
            c->advocateFullname = c->advocateFullname->Trim();

            c->fullname = gcnew String(fullname.c_str());
            c->fullname = c->fullname->Trim();

            c->phone = gcnew String(phone.c_str());
            c->phone = c->phone->Trim();

            c->email = gcnew String(email.c_str());
            c->email = c->email->Trim();

            return c;
        }
    }

    return nullptr;
}

bool ClientManager::editClient(String^ id, String^ fullname, String^ phone, String^ email, String^ filename) {
    std::string nativeFullname = msclr::interop::marshal_as<std::string>(fullname->Trim());
    std::string nativePhone = msclr::interop::marshal_as<std::string>(phone->Trim());
    std::string nativeEmail = msclr::interop::marshal_as<std::string>(email->Trim());
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());
    std::string nativeId = msclr::interop::marshal_as<std::string>(id->Trim());

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
        std::string existingId, existingAdvocateFullname, existingFullname, existingPhone, existingEmail;

        std::getline(ss, existingId, '|');
        std::getline(ss, existingAdvocateFullname, '|');
        std::getline(ss, existingFullname, '|');
        std::getline(ss, existingPhone, '|');
        std::getline(ss, existingEmail, '|');

        existingId.erase(0, existingId.find_first_not_of(" \t\n\r"));
        existingId.erase(existingId.find_last_not_of(" \t\n\r") + 1);

        if (existingId == nativeId) {
            lines[i] = existingId + " | " + existingAdvocateFullname 
                + " | " + nativeFullname + " | " + nativePhone 
                + " | " + nativeEmail;
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

bool ClientManager::deleteClient(String^ id, String^ filename) {
    std::string nativeId = msclr::interop::marshal_as<std::string>(id->Trim());
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());

    std::ifstream fin(nativeFilename);
    std::vector<std::string> lines;
    std::string line;

    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::string clientId, advocateFullname, fullname, phone, email;
        ss >> clientId >> advocateFullname >> fullname >> phone >> email;
        String^ clientIdStr = gcnew String(clientId.c_str());

        if (clientIdStr == id) {
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