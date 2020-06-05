#include <bits/stdc++.h>

using namespace std;


int main(){

    unordered_map<char,int> map;
    map['A'] = -1;
    map['E'] = -1;
    map['I'] = -1;
    map['O'] = -1;
    map['U'] = -1;
    map['H'] = -1;
    map['W'] = -1;
    map['Y'] = -1;
    map['B'] = 1;
    map['F'] = 1;
    map['P'] = 1;
    map['V'] = 1;
    map['C'] = 2;
    map['G'] = 2;
    map['J'] = 2;
    map['K'] = 2;
    map['Q'] = 2;
    map['S'] = 2;
    map['X'] = 2;
    map['Z'] = 2;
    map['D'] = 3;
    map['T'] = 3;
    map['L'] = 4;
    map['M'] = 5;
    map['N'] = 5;
    map['R'] = 6;

    string s;
    while(cin >> s){
        int prev = 0;
        for(int i = 0;i<s.size();i++){
            if(map.at(s[i]) == -1){
                prev = 0;

            }
            else if(prev == 0 || map.at(s[i]) != prev){

                   cout << map.at(s[i]);
                   prev = map.at(s[i]);
            }

        }
        cout << endl;
    }
    return 0;
}
