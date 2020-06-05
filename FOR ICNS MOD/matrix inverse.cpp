//
//  main.cpp
//  November Challange
//
//  Created by Joy Brahma on 02/11/19.
//  Copyright © 2019 Joy Brahma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <math.h>
#include <limits>
#include <iomanip>
#define DBL_MAX 1.7976931348623158e+308
using namespace std;
typedef unsigned long long int ull;
typedef long double ld;
# define N 4
int adj[N][N]={0};

void cofactor(int A[N][N],int temp[N][N],int p,int q,int n){
    int i = 0,j = 0;
    for(int x  = 0;x<n;x++){
        for(int y = 0;y<n;y++){
            if(x != p && y!= q){
                temp[i][j++] = A[x][y];

                if(j == n-1){
                    j = 0;i++;
                }

            }
        }
    }
}

int det(int A[N][N],int n){
    int D = 0;
    if(n==1)
        return A[0][0];

    int s = 1;
    int temp[N][N];

    for(int i = 0;i<n;i++){
        cofactor(A, temp , 0, i, n);
        D += s*A[0][i]*det(temp,n-1);
        s = -s;
    }
    return D;
}

void adjoint(int A[N][N],int mods,int deti){
    if(N == 1){
        adj[0][0] = 1;
    }
    int s  = 1;
    int temp[N][N];

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cofactor(A,temp,i,j,N);
            if((i+j)%2 == 0)
                s = 1;
            else
                s = -1;

            adj[j][i] = (s*det(temp,N-1)*deti)%mods;
            adj[j][i] = (adj[j][i]+mods) % mods;
        }
    }

}
int inverse(int n,int mod){
    for(int i =1;i<mod;i++){
        if( (i*n)%mod  == 1)
            return i;

    }
    return -1;

}
void inv(int A[N][N],int mod){
    int dets = det(A,N);
    int deti = inverse(dets,mod);
    adjoint(A,mod,deti);
}


int main(){
    int n = 4;
    int a;
    int A[N][N];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> a;
            A[i][j] = a;
        }
    }
    cout<<det(A,N);
    inv(A,13);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }





}
