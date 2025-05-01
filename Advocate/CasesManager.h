#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Collections::Generic;

ref class Case {
public:
    String^ id;
    String^ advocateFullname;
    String^ clientId;
    String^ title;
    String^ description;
    String^ status;
    String^ created;
};

ref class CasesManager {
public:
    List<Case^>^ readAllCases(String^ filename);
    List<Case^>^ readClientCases(String^ clientId, String^ filename);
    Case^ getOne(String^ id, String^ filename);
    bool addCase(String^ advocateFullname, String^ clientId, String^ title, String^ description, String^ status, String^ filename);
    bool editCase(String^ id, String^ title, String^ description, String^ status, String^ filename);
    bool deleteCase(String^ id, String^ filename);
};

