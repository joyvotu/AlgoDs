//
//  main.cpp
//  test02
//
//  Created by Joy Brahma on 08/02/20.
//  Copyright © 2020 Joy Brahma. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    string s,s1;

    bool val;

    while(1){
        getline(cin,s);

        if(s!="#"){
        val = next_permutation(s.begin(),s.end());
        if(val == false){
            cout<< "No Successor" << endl;
        }else{
            cout << s << endl;
        }
    }

        else{
            break;
        }


    }
    return 0;

}
