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
    
    //check if first char is +, -, or number
    if (plusminus.find(str[0]) == string::npos && NUMS.find(str[0]) == string::npos)
        return 0;

    for (int i=1; i < str.length(); i++){
        //check if char is number
        if (NUMS.find(str[i]) == string::npos)
            return 0;
    }
    return 1;
}

bool find_decimal(string str){

    string plusminus = "+-";
    bool found_dot = 0;
    
    //check if first char is +, -, or number
    if (plusminus.find(str[0]) == string::npos && NUMS.find(str[0]) == string::npos)
        return 0;

    for (int i=1; i < str.length(); i++){
        //check if char is dot
        //if dot already found, fail
        if (str[i] == '.'){
            if (found_dot == 0){
                found_dot = 1;
                continue;
            }else{
                return 0;
            }
        }

        //check if char is number
        if (NUMS.find(str[i]) == string::npos)
            return 0;
    }
    return 1;

}

bool find_scientific(string str){

    string before_E = "";
    string after_E = "";

    //find E in string
    int E_location = str.find('E');

    //if E not in string, fail
    //otherwise split string into before and after E
    if (E_location != string::npos){
        before_E = str.substr(0, E_location);
        after_E = str.substr(E_location+1, str.length()-E_location+1);
    } else {
        return 0;
    }

    //check if before E is a decimal and after E is an integer
    if (find_decimal(before_E) && find_integer(after_E)){
        return 1;
    }
    return 0;
}

bool find_hexadecimal(string str){

    for (int i=1; i < str.length()-1; i++){
        //check if char is a hex char
        if (NUMS.find(str[i]) == string::npos && ATOF.find(str[i]) == string::npos)
            return 0;
    }

    //check if last char is H
    if (str.back() == 'H')
        return 1;

    return 0;
}

bool find_character_literal(string str){

    //fail if length of string is not 3
    if (str.length() != 3)
        return 0;

    for (int i=0; i < 2; i++){
        //check if char is a hex char
        if (NUMS.find(str[i]) == string::npos && ATOF.find(str[i]) == string::npos)
            return 0;
    }

    //check if last char is X
    if (str[2] == 'X')
        return 1;

    return 0;
}

bool find_keyword(string str){

    //check if str is a keyword
    for (int i=0; i < sizeof(KEYWORDS)/sizeof(KEYWORDS[0]); i++){
        if (KEYWORDS[i] == str)
            return 1;
    }
    
    return 0;
}

bool find_string_literal(string str){

    //make sure string has at least 2 chars
    if (str.length() <= 1)
        return 0;

    //fail if string does not start and end with "
    if (str[0] == '\"' && str.back() == '\"'){
    }else{
        return 0;
    }

    for (int i=1; i < str.length()-1; i++){
        //check if char is space or "
        if (str[i] == ' ' || str[i] == '\"'){
            return 0;
        } 
    }

    return 1;
}

bool find_aircraft_designation(string str){

    int place_num = 2;
    int length = str.length();

    //check that first char is a type description and second char is a number
    if (TYPE_DES.find(str[0]) != string::npos && NUMS.find(str[1]) != string::npos){
        //check if third char is a number
        if (NUMS.find(str[2]) != string::npos)
            //if so, move place_num forward
            place_num += 1;
        //check if char is a manufacturer description
        if (MAN_DES.find(str[place_num]) != string::npos)
            //if string continues, move place_num forward
            if (length > place_num+1){
                place_num += 1;
                //check if char is a number
                if (NUMS.find(str[place_num]) != string::npos){
                    //if string continues, move place_num forward
                    if (length > place_num+1){
                        place_num += 1;
                        //check if char is a number
                        if (NUMS.find(str[place_num]) != string::npos)
                            //if so, move place_num forward
                            place_num += 1;
                        //if string ends, pass
                        if (length > place_num+1){
                            //check if char is a dash
                            if (str[place_num] == '-'){
                                //if string stops, fail, otherwise continue
                                if (length > place_num+1){
                                    //move place_num forward
                                    place_num += 1;
                                    //if char is a type description and the string stops, pass, otherwise fail
                                    if (TYPE_DES.find(str[place_num]) != string::npos && length == place_num+1){
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

    //check if first char is a letter
    if (ALPHABET.find(str[0]) == string::npos)
        return 0;

    for (int i=1; i < str.length(); i++){
        //check if char is a letter, number, or underscore
        if (ALPHABET.find(str[i]) == string::npos && NUMS.find(str[i]) == string::npos && str[i] != '_')
            return 0;
    }
    return 1;
}

bool find_phone_number(string str){

    string new_str = "";
    int length = str.length();

    //check if string is long enough to be a phone number
    //prevents out of bounds indexing
    if (length < 12 || length > 13){
        return 0;
    }

    //check if string follows any of the three phone number formats
    if ((str[3] == '.' && str[7] == '.' && length == 12) || (str[3] == '-' && str[7] == '-' && length == 12) || (str[0] == '(' && str[4] == ')' && str[8] == '-' && length == 13)){
        //if so, puts all numbers in string into new string
        for (int i=0; i < str.length(); i++){
            //if char is a number, add it to new string
            if (NUMS.find(str[i]) != string::npos)
                new_str += str[i];
        }
    }
    
    //if new string has a length of 10, pass
    if (new_str.length() == 10)
        return 1;
    return 0;
}

string find_type(string str){

    //check string against each type and return the corresponding type name
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

    //otherwise return invalid
    return "INVALID!";
}
