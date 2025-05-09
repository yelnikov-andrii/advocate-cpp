#include "CasesManager.h"
#include <fstream>
#include <sstream>
#include <ctime>

using namespace System;
using namespace System::Collections::Generic;

List<Case^>^ CasesManager::readAllCases(String^ filename) {
    List<Case^>^ cases = gcnew List<Case^>();

    std::ifstream fin(msclr::interop::marshal_as<std::string>(filename->Trim()));

    std::string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string id, advocateFullname, clientId, title, description, status, created;

        std::getline(ss, id, '|');
        std::getline(ss, advocateFullname, '|');
        std::getline(ss, clientId, '|');
        std::getline(ss, title, '|');
        std::getline(ss, description, '|');
        std::getline(ss, status, '|');
        std::getline(ss, created, '|');

        Case^ caseObj = gcnew Case();
        caseObj->id = gcnew String(id.c_str());
        caseObj->id = caseObj->id->Trim();

        caseObj->advocateFullname = gcnew String(advocateFullname.c_str());
        caseObj->advocateFullname = caseObj->advocateFullname->Trim();

        caseObj->clientId = gcnew String(clientId.c_str());
        caseObj->clientId = caseObj->clientId->Trim();

        caseObj->title = gcnew String(title.c_str());
        caseObj->title = caseObj->title->Trim();

        caseObj->description = gcnew String(description.c_str());
        caseObj->description = caseObj->description->Trim();

        caseObj->status = gcnew String(status.c_str());
        caseObj->status = caseObj->status->Trim();

        caseObj->created = gcnew String(created.c_str());
        caseObj->created = caseObj->created->Trim();

        cases->Add(caseObj);
    }

    fin.close();
    return cases;
}

List<Case^>^ CasesManager::readClientCases(String^ clientIdParam, String^ filename) {
    List<Case^>^ cases = gcnew List<Case^>();

    std::ifstream fin(msclr::interop::marshal_as<std::string>(filename->Trim()));

    std::string line;
    Console::WriteLine("Console is running");
    while (getline(fin, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string id, advocateFullname, clientId, title, description, status, created;

        std::getline(ss, id, '|');
        std::getline(ss, advocateFullname, '|');
        std::getline(ss, clientId, '|');
        std::getline(ss, title, '|');
        std::getline(ss, description, '|');
        std::getline(ss, status, '|');
        std::getline(ss, created, '|');

        String^ clientIdStr = gcnew String(clientId.c_str());
        clientIdStr = clientIdStr->Trim();
        clientIdParam = clientIdParam->Trim();

        if (clientIdStr != clientIdParam) {
            continue;
        }

        Case^ caseObj = gcnew Case();
        caseObj->id = gcnew String(id.c_str());
        caseObj->id = caseObj->id->Trim();

        caseObj->advocateFullname = gcnew String(advocateFullname.c_str());
        caseObj->advocateFullname = caseObj->advocateFullname->Trim();

        caseObj->clientId = gcnew String(clientId.c_str());
        caseObj->clientId = caseObj->clientId->Trim();

        caseObj->title = gcnew String(title.c_str());
        caseObj->title = caseObj->title->Trim();

        caseObj->description = gcnew String(description.c_str());
        caseObj->description = caseObj->description->Trim();

        caseObj->status = gcnew String(status.c_str());
        caseObj->status = caseObj->status->Trim();

        caseObj->created = gcnew String(created.c_str());
        caseObj->created = caseObj->created->Trim();

        cases->Add(caseObj);
    }

    fin.close();
    return cases;
}

bool CasesManager::addCase(String^ advocateFullname, String^ clientId, String^ title, String^ description, String^ status, String^ filename) {
    std::string nativeAdvocateFullname = msclr::interop::marshal_as<std::string>(advocateFullname->Trim());
    std::string nativeClientId = msclr::interop::marshal_as<std::string>(clientId->Trim());
    std::string nativeTitle = msclr::interop::marshal_as<std::string>(title->Trim());
    std::string nativeDescription = msclr::interop::marshal_as<std::string>(description->Trim());
    std::string nativeStatus = msclr::interop::marshal_as<std::string>(status->Trim());
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());
    std::ofstream idFile("casesLastId.txt", std::ios::app);
    
    int caseId = 0;
    std::ifstream idIn("casesLastId.txt");

    if (idIn.is_open()) {
        idIn >> caseId;
        idIn.close();
    }
    caseId++;

    std::ofstream outFile(nativeFilename, std::ios::app);
    if (!outFile.is_open()) return false;

    time_t now = time(0);
    tm* ltm = localtime(&now);

    char createdAt[11];
    strftime(createdAt, sizeof(createdAt), "%Y-%m-%d", ltm);

    outFile << caseId << " | " << nativeAdvocateFullname << " | " << nativeClientId << " | "
        << nativeTitle << " | " << nativeDescription << " | " << nativeStatus << " | " << createdAt << std::endl;
    outFile.close();

    std::ofstream idOut("casesLastId.txt", std::ios::trunc);
    if (idOut.is_open()) {
        idOut << caseId;
        idOut.close();
    }

    return true;
}

Case^ CasesManager::getOne(String^ id, String^ filename) {
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());
    std::string nativeId = msclr::interop::marshal_as<std::string>(id->Trim());

    std::ifstream file(nativeFilename);
    if (!file.is_open()) return nullptr;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string caseId, advocateFullname, clientId, title, description, status, created;

        std::getline(ss, caseId, '|');
        std::getline(ss, advocateFullname, '|');
        std::getline(ss, clientId, '|');
        std::getline(ss, title, '|');
        std::getline(ss, description, '|');
        std::getline(ss, status, '|');
        std::getline(ss, created, '|');
        String^ caseIdStr = gcnew String(caseId.c_str());
        caseIdStr = caseIdStr->Trim();

        if (caseIdStr == id) {
            Case^ caseObj = gcnew Case();
            caseObj->id = gcnew String(caseId.c_str());
            caseObj->id = caseObj->id->Trim();

            caseObj->advocateFullname = gcnew String(advocateFullname.c_str());
            caseObj->advocateFullname = caseObj->advocateFullname->Trim();

            caseObj->clientId = gcnew String(clientId.c_str());
            caseObj->clientId = caseObj->clientId->Trim();

            caseObj->title = gcnew String(title.c_str());
            caseObj->title = caseObj->title->Trim();

            caseObj->description = gcnew String(description.c_str());
            caseObj->description = caseObj->description->Trim();

            caseObj->status = gcnew String(status.c_str());
            caseObj->status = caseObj->status->Trim();

            caseObj->created = gcnew String(created.c_str());
            caseObj->created = caseObj->created->Trim();

            return caseObj;
        }
    }

    return nullptr;
}

bool CasesManager::editCase(String^ id, String^ title, String^ description, String^ status, String^ filename) {
    std::string nativeId = msclr::interop::marshal_as<std::string>(id->Trim());
    std::string nativeTitle = msclr::interop::marshal_as<std::string>(title->Trim());
    std::string nativeDescription = msclr::interop::marshal_as<std::string>(description->Trim());
    std::string nativeStatus = msclr::interop::marshal_as<std::string>(status->Trim());
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());
    std::ofstream idFile("casesLastId.txt", std::ios::app);

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
        std::string existingId, existingAdvocateFullname, existingClientId, 
            existingTitle, existingDescription, existingStatus, existingCreated;

        std::getline(ss, existingId, '|');
        std::getline(ss, existingAdvocateFullname, '|');
        std::getline(ss, existingClientId, '|');
        std::getline(ss, existingTitle, '|');
        std::getline(ss, existingDescription, '|');
        std::getline(ss, existingStatus, '|');
        std::getline(ss, existingCreated, '|');

        existingId.erase(0, existingId.find_first_not_of(" \t\n\r"));
        existingId.erase(existingId.find_last_not_of(" \t\n\r") + 1);

        if (existingId == nativeId) {
            lines[i] = existingId + " | " + existingAdvocateFullname
                + " | " + existingClientId + " | " + nativeTitle
                + " | " + nativeDescription
                + " | " + nativeStatus
                + " | " + existingCreated;
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

bool CasesManager::deleteCase(String^ id, String^ filename) {
    std::string nativeFilename = msclr::interop::marshal_as<std::string>(filename->Trim());
    String^ idStr = id->Trim();

    std::ifstream fin(nativeFilename);
    std::vector<std::string> lines;
    std::string line;

    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::string caseId, advocateFullname, clientId, title, description, status, created;
        ss >> caseId >> advocateFullname >> clientId >> title >> description >> status >> created;
        String^ caseIdStr = gcnew String(caseId.c_str());
        caseIdStr = caseIdStr->Trim();

        if (caseIdStr == idStr) {
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