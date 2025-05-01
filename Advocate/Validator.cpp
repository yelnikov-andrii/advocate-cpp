#include "Validator.h"

using namespace System::Text::RegularExpressions;

bool Validator::IsValidEmail(String^ email) {
    String^ pattern = "^\\S+@\\S+\\.\\S+$";
    return Regex::IsMatch(email, pattern);
}

bool Validator::IsValidPhone(String^ phone) {
    String^ pattern = "^\\+380\\d{9}$";
    return Regex::IsMatch(phone, pattern);
}
