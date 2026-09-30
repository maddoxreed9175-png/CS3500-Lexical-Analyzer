#include <string>
using namespace std;

bool find_integer(string str){

    return 0;
}

bool find_decimal(string str){

    return 0;
}

bool find_scientific(string str){

    return 0;
}

bool find_hexadecimal(string str){

    return 0;
}

bool find_character_literal(string str){

    return 0;
}

bool find_keyword(string str){

    return 0;
}

bool find_string_literal(string str){

    return 0;
}

bool find_aircraft_designation(string str){

    return 0;
}

bool find_identifier(string str){
    
    return 0;
}

bool find_phone_number(string str){

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
