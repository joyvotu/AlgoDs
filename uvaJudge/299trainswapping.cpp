//
//  main.cpp
//  sorting problems
//
//  Created by Joy Brahma on 09/02/20.
//  Copyright © 2020 Joy Brahma. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int bubblesort(int arr[],int n){
    int res = 0;
    if(n < 2)
        return 0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                res++;
            }
        }
    }

    return res;

}


int main(){
    int test;
    cin >> test;
    while(test--){
    int arr[55];

    int size;
    cin >> size;

    for(int i = 0;i<size;i++){
        scanf("%d", &arr[i]);
    }

        printf("Optimal train swapping takes %d swaps.\n", bubblesort(arr,size));

}

    return 0;
}
