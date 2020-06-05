//
//  main.cpp
//  test10
//
//  Created by Joy Brahma on 11/02/20.
//  Copyright © 2020 Joy Brahma. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
bool comp(char a,char b){
    if(a == '(' && b == ')')
        return true;
    if(a == '[' && b == ']')
        return true;
    return false;
}
int main(){
    stack<char> s;

    int n;
    string s1;
    char c;
    scanf("%d", &n);
    getchar();
    while(n--){
       while(!s.empty())
           s.pop();
        getline(cin,s1);


        istringstream ss(s1);
        while(ss >> c){
            if(c == '(' || c == ')' || c == '[' || c==']'){
                if(s.empty() || !comp(s.top(),c))
                    s.push(c);
                if(comp(s.top(),c)){
                    s.pop();
                }
            }

        }
        if(s.empty())
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
