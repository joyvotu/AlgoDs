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

void swap(char *a,char *b){
    if(*a==*b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;

}

void reverse(string &s,int l,int r){
    while(l < r){
        swap(&s[l++],&s[r--]);
    }

}

int bsearch(string &s,int l,int r,int key){
    int ind = -1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(s[m]<=key)
            r = m-1;
        else{
            l = m+1;
            if(ind == -1 || s[ind] >= s[m])
                ind = m;
        }
    }
    return ind;
}

bool nperm(string &s){
    int l = s.size();
    int i = l-2;
    while(i>=0 && s[i]>=s[i+1])
        i--;
    if(i<0)
        return false;
    else{
        int id = bsearch(s,i+1,l-1,s[i]);
        swap(&s[i] , &s[id]);
        reverse(s,i+1,l-1);
        return true;
    }

}


int main(){
    string s;
    while(true){
        getline(cin,s);
        if(s == "#")
            return 0;
        if(nperm(s)){
            cout << s << endl;
        }else{
            cout << "No Successor" << endl;
        }
    }
    return 0;
}
