#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,n) for(int  i = 0;i<n;i++)
using namespace std;

int find(int arr[],int l,int r,int k){
    while(l <= r){
        int m = l+(r-l)/2;
        if(arr[m] == k)
            return m;
        else if(m-1 >= l && arr[m-1] == k)
            return m-1;
        else if(m+1 <= r && arr[m+1] == k)
            return m+1;
        else if(arr[m] < k)
            l = m+2;
        else
            r = m-2;


    }
    return -1;
}


int main(){
    int arr[] = {2,1,3,5,4,7,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << find(arr,0,n-1,5);
}
10 30 6 8 --> 54 = 27 , 11/2 = 5;
