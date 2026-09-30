#include <string>
using namespace std;

const string NUMS = "0123456789";
const string ATOF = "ABCDEF";
const string DOT = ".";

bool find_integer(string str){
    
    string plusminus = "+-";
    if (plusminus.find(str[0]) == string::npos && NUMS.find(str[0]) == string::npos)
        return 0;
    for (int i=1; i < str.length(); i++){
        if (NUMS.find(str[i]) == string::npos)
            return 0;
    }
    return 1;
}

bool find_decimal(string str){

    string plusminus = "+-";
    bool found_dot = 0;

    if (plusminus.find(str[0]) == string::npos && NUMS.find(str[0]) == string::npos)
        return 0;

    for (int i=1; i < str.length(); i++){
        if (DOT.find(str[i]) != string::npos){
            if (found_dot == 0){
                found_dot == 1;
                continue;
            }else{
                return 0;
            }
        }
        if (NUMS.find(str[i]) == string::npos)
            return 0;
    }
    return 1;

}

bool find_scientific(string str){

    string before_E = "";
    string after_E = "";

    int E_location = str.find('E');
    if (E_location != string::npos){
        before_E = str.substr(0, E_location);
        after_E = str.substr(E_location+1, str.length()-E_location+1);
    } else {
        return 0;
    }

    if (find_decimal(before_E) && find_integer(after_E)){
        return 1;
    }
    return 0;
}

bool find_hexadecimal(string str){

    for (int i=0; i < str.length(); i++){

    }
    return 0;
}

bool find_character_literal(string str){

    for (int i=0; i < str.length(); i++){

    }
    return 0;
}

bool find_keyword(string str){

    for (int i=0; i < str.length(); i++){

    }
    return 0;
}

bool find_string_literal(string str){

    for (int i=0; i < str.length(); i++){

    }
    return 0;
}

bool find_aircraft_designation(string str){

    for (int i=0; i < str.length(); i++){

    }
    return 0;
}

bool find_identifier(string str){
    for (int i=0; i < str.length(); i++){

    }
    return 0;
}

bool find_phone_number(string str){

    for (int i=0; i < str.length(); i++){

    }
    return 0;
}

string find_type(string str){

    if (find_integer(str))
        return "Integer";
    if (find_decimal(str))
        return "Decimal";
    if (find_scientific(str))
        return "Scientific";
    if (find_hexadecimal(str))
        return "Hexadecimal";
    if (find_character_literal(str))
        return "Character";
    if (find_keyword(str))
        return "Keyword";
    if (find_string_literal(str))
        return "String";
    if (find_aircraft_designation(str))
        return "Aircraft";
    if (find_identifier(str))
        return "Identifier";
    if (find_phone_number(str))
        return "Phone";

    return "INVALID!";
}
