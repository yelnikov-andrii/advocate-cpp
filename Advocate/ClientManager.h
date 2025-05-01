#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Collections::Generic;

ref class Client {
public:
    String^ id;
    String^ advocateFullname;
    String^ fullname;
    String^ phone;
    String^ email;
};

ref class ClientManager {
public:
    List<Client^>^ readClientsFromFile(String^ fullname, String^ filename);
    bool addClient(String^ advocateFullname, String^ fullname, String^ phone, String^ email, String^ filename);
    Client^ getOne(String^ id, String^ filename);
    bool editClient(String^ id, String^ fullname, String^ phone, String^ email, String^ filename);
    bool deleteClient(String^ id, String^ filename);
};