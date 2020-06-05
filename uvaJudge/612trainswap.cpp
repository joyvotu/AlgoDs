//
//  main.cpp
//  sorting problems
//
//  Created by Joy Brahma on 09/02/20.
//  Copyright © 2020 Joy Brahma. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;

struct sq{
    string ch;
    int inv;

};

int inversion(string a){
    int n = a.size();
    int count  = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(a[i]>a[j]){
                count++;
            }
        }
    }

    return count;
}
bool cmp(sq a,sq b){
    return a.inv < b.inv;
}
int main(){
    int t,n,m;
    cin >>t;
    getchar();
    sq a[102];
    string s;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0;i<m;i++){
            cin >> s;
            a[i].ch = s;
            a[i].inv = inversion(s);

        }
        stable_sort(a,a+m,cmp);
        for(int i = 0;i<m;i++){
            cout << a[i].ch << endl;
        }
        cout << endl;


    }
    return 0;


}
