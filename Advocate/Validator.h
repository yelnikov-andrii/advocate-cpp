#pragma once

using namespace System;
using namespace System::Text::RegularExpressions;

ref class Validator {
public:
    static bool IsValidEmail(String^ email);
    static bool IsValidPhone(String^ phone);
};


