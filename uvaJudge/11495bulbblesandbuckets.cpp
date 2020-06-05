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

int arr[1000005];
ll cnt = 0;

void merge(int *arr,int l,int m,int r){
    int n1  = m-l+1;
    int n2 = r-m;
    int ba[n1],dan[n2];
    for(int i = 0;i<n1;i++){
        ba[i] = arr[l+i];
    }
    for(int j = 0;j<n2;j++){
        dan[j] = arr[m+1+j];

    }

    int i = 0, j = 0 , k = l;
    while(i < n1 && j<n2){
        if(ba[i] <= dan[j]){

            arr[k++] = ba[i++];

        }else{
            arr[k++] = dan[j++];
             cnt += n1 - i;

        }

    }

    while(i<n1){
        arr[k++] = ba[i++];
    }
    while(j < n2){
        arr[k++] =  dan[j++];
    }

}

void mergesort(int *a,int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }

}

int main(){
    string s;
    int n;
    while(1){
        cnt = 0;
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }

        mergesort(arr,0,n-1);
        if(cnt%2 == 1)
           cout<<"Marcelo"<<endl;

        else

            cout<<"Carlos"<<endl;

    }

    return 0;
}
