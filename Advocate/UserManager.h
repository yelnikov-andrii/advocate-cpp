#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Collections::Generic;

ref class User {
public:
    String^ fullname;
    String^ password;
    String^ role;
};

ref class UserManager {
public:
    List<User^>^ readUsersFromFile(String^ filename);
    bool addUser(String^ fullname, String^ role, String^ password, String^ filename);
    bool editUser(String^ oldfullname, String^ fullname, String^ role, String^ password, String^ filename);
    bool deleteUser(String^ fullname, String^ filename);
};
