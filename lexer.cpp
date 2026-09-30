#include <iostream>
#include <string>
#include "regex.h"

using namespace std;

int main(){

    int T;

    string s;

    //get number of strings that will be checked
    cin >> T;

    cin.ignore();

    //output number of strings that will be checked
    cout << T << endl;

    for (int i=0; i<T; i++){
        //get new string
        getline(cin, s);
        //output string type
        cout << i+1 << ": " << find_type(s) << endl;
    }

    return 0;
}
