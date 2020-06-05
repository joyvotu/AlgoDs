#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,n) for(int  i = 0;i<n;i++)
using namespace std;

int ceil(int arr[],int l,int r,int key){
    int ceil = -1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m] == key)
            return arr[m];
        else if(arr[m] > key){
            ceil = arr[m];
            r  = m-1;
        }
        else
            l = m+1;

    }
    return ceil;
}


int floor(int arr[],int l,int r,int key){
    int floor = -1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m] == key)
            return arr[m];
        else if(arr[m] < key){
            floor = arr[m];
            l = m+1;
        }
        else
            r = m-1;

    }
    return floor;
}
int main(){
    int arr[] = {1,4,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    fr(i,10){
        cout << i << " " << "FLOOR " << floor(arr,0,n-1,i) << " ceil " << ceil(arr,0,n-1,i) << endl;
    }
}
