#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int findFirstOccur(int arr[],int l,int h,int k){
    int res =-1;
    while(l<=h){
        int m = l+((h-l)/2);

        if(arr[m] == k){
            res = m;
            h = m-1;
        }
        else if(arr[m]>k){
            h =  m-1;
        }else{
            l = m+1;
        }
    }
    return res;
}

int findLastOccur(int arr[],int l,int h,int k){
    int res =-1;
    while(l<=h){

        int m = l+((h-l)/2);

        if(arr[m] == k){
            res = m;
            l = m+1;
        }
        else if(arr[m]>k){
            h =  m-1;
        }else{
            l = m+1;
        }
    }
    return res;

}

int main(){
    int arr[] = {2,5,5,6,8,8,9,9,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findFirstOccur(arr, 0, n-1, 9) << " " << findLastOccur(arr, 0, n-1,9);

}
