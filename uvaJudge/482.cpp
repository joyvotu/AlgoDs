//
//  main.cpp
//  tester
//
//  Created by Joy Brahma on 25/01/20.
//  Copyright © 2020 Joy Brahma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>


using namespace std;


int main(){
    int t,a;
    string r[100000];

    vector<int> v;
    string s;
    vector<string> d;

    cin >> t;
    //cin.ignore();
    getchar();
    while(t--){

        string line,lined;
        getchar();
        getline(cin,line);

        getline(cin,lined);



        stringstream p(line);
        stringstream pd(lined);

        while(p >> a)
            v.push_back(a);

        while(pd >> s)
            d.push_back(s);

         for(int i = 0;i<v.size();i++){
             r[v[i]] = d[i];
        }


        for(int i = 1;i<v.size()+1;i++){
            cout << r[i] << endl;
        }
        if(t)
            cout << endl;

        d.clear();
        v.clear();
        for(int i = 0;i<100000;i++)
            r[i] = "";


    }

    return 0;



}
