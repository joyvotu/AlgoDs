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

ll ar[1000005];
ll cnt;
void merge(ll *arr,int l,int m,int r){

    int n1 = m-l+1;
    int n2 = r-m;

    ll ba[n1],dan[n2];
    for(int i = 0;i<n1;i++){
        ba[i] = arr[l+i];
    }
    for(int i = 0;i<n2;i++){
        dan[i] = arr[m+1+i];
    }

    int i = 0,j = 0 , k = l;

    while(i < n1 && j < n2){
        if(ba[i]<=dan[j]){
            arr[k++] = ba[i++];


        }else{
            arr[k++] = dan[j++];
            cnt += n1-i;
        }
    }
    while(i < n1){
        arr[k++] = ba[i++];

    }
    while(j < n2){
        arr[k++] =  dan[j++];
    }

}

void mergesort(ll *a,int l,int r){

    if(l < r){
        int m = l+(r-l)/2;
       mergesort(a,l,m);
        mergesort(a, m+1, r);
       merge(a,l,m,r);
    }

}
int main(){
    int n;
    while(cin >> n && n != 0){
        cnt  = 0;
        ll b;
        for(int i = 0;i<n;i++){
            cin >> b;
            ar[i] = b;
        }
        mergesort(ar,0,n-1);
        cout << cnt << endl;
    }
    return 0;
}
