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
    int t,k,m;
    long long c;
    string line;
    char a;
    int b;
    unordered_map<char, int> list;
    unordered_map<char, ll> map;

    scanf("%d", &t);
    while(t--){
        scanf("%d" , &k);
        while(k--){
            cin >> a >> b;
            list[a] = b;
        }
        scanf("%d", &m);
        getchar();
        while(m--){

            getline(cin,line);
            for(int i = 0;i<line.size();i++){
                map[line[i]]++;

            }
        }
        c = 0;
        for(auto it = list.begin();it!=list.end();it++){
            c += map[it->first]*it->second;
        }
        list.clear();
        map.clear();
        printf("%.2f$\n", c/100.0);

    }

    return 0;



}
