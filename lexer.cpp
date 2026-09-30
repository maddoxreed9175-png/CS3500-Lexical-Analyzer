#include <iostream>
#include <string>
#include "regex.h"

using namespace std;

int main(){

    int T;

    string s;

    cin >> T;

    cin.ignore();

    cout << T << endl;

    for (int i=0; i<T; i++){
        getline(cin, s);
        cout << i+1 << ": " << find_type(s) << endl;
    }

    return 0;
}
