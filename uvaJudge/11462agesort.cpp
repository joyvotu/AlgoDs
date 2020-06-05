//
//  main.cpp
//  sorting problems
//
//  Created by Joy Brahma on 09/02/20.
//  Copyright © 2020 Joy Brahma. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[105];

void init(){
    for(int i = 0;i<101;i++){
        a[i] = 0;
    }
}
int main(){
    ll n;
    int b;
    while(1){
    init();
    scanf("%lld" , &n);
    if(n == 0)
        break;
    getchar();
    for(ll i = 0;i<n;i++){
        scanf("%d ", &b);
        a[b]++;
    }

        int j;

        for(int i = 0;i<101;i++){
            j = i;
            while(a[j] != 0){
                printf("%d ",j);
                a[j]--;
            }

        }
        cout << endl;




    }

    return 0;
}
