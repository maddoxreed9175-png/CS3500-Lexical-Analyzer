#include <string>
using namespace std;

const string NUMS = "0123456789";
const string ATOF = "ABCDEF";
const string KEYWORDS[6] = {"FOO", "IF", "FI", "LOOP", "POOL", "PRINT"};
const string TYPE_DES = "AGJDPL";
const string MAN_DES = "AKMNY";
const string ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
        if (str[i] == '.'){
            if (found_dot == 0){
                found_dot = 1;
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

    for (int i=1; i < str.length()-1; i++){
        if (NUMS.find(str[i]) == string::npos && ATOF.find(str[i]) == string::npos)
            return 0;
    }

    if (str.back() == 'H')
        return 1;

    return 0;
}

bool find_character_literal(string str){

    if (str.length() != 3)
        return 0;

    for (int i=0; i < 2; i++){
        if (NUMS.find(str[i]) == string::npos && ATOF.find(str[i]) == string::npos)
            return 0;
    }

    if (str[2] == 'X')
        return 1;

    return 0;
}

bool find_keyword(string str){

    for (int i=0; i < sizeof(KEYWORDS)/sizeof(KEYWORDS[0]); i++){
        if (KEYWORDS[i] == str)
            return 1;
    }
    
    return 0;
}

bool find_string_literal(string str){

    if (str.length() <= 1)
        return 0;

    if (str[0] == '\"' && str.back() == '\"'){
    }else{
        return 0;
    }

    for (int i=1; i < str.length()-1; i++){
        if (str[i] == ' ' || str[i] == '\"'){
            return 0;
        } 
    }

    return 1;
}

bool find_aircraft_designation(string str){

    int place_num = 2;

    

    if (TYPE_DES.find(str[0]) != string::npos && NUMS.find(str[1]) != string::npos){
        if (NUMS.find(str[2]) != string::npos)
            place_num = 3;
        if (MAN_DES.find(str[place_num]) != string::npos)
            if (str.length() > place_num+1){
                place_num += 1;
                if (NUMS.find(str[place_num]) != string::npos){
                    if (str.length() > place_num+1){
                        place_num += 1;
                        if (NUMS.find(str[place_num]) != string::npos)
                            place_num += 1;
                        if (str.length() > place_num+1){
                            if (str[place_num] == '-'){
                                if (str.length() > place_num+1){
                                    place_num += 1;
                                    if (TYPE_DES.find(str[place_num]) != string::npos){
                                        return 1;
                                    }else{
                                        return 0;
                                    }
                                }
                            }else{
                                return 0;
                            }
                        }else{
                            return 1;
                        }
                    }else{
                        return 1;
                    }
                }else{
                    return 0;
                }
            }else{
                return 1;
            }

            
    }
    return 0;
}

bool find_identifier(string str){

    if (ALPHABET.find(str[0]) == string::npos)
        return 0;

    for (int i=1; i < str.length(); i++){
        if (ALPHABET.find(str[i]) == string::npos && NUMS.find(str[i]) == string::npos && str[i] != '_')
            return 0;
    }
    return 1;
}

bool find_phone_number(string str){

    string new_str = "";

    if (str.length() < 12){
        return 0;
    }

    if ((str[3] == '.' && str[7] == '.') || (str[3] == '-' && str[7] == '-') || (str[0] == '(' && str[4] == ')' && str[8] == '-')){
        for (int i=0; i < str.length(); i++){
            if (NUMS.find(str[i]) != string::npos)
                new_str += str[i];
        }
    }

    return find_integer(new_str);
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
