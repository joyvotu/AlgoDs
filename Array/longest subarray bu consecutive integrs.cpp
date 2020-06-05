#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,n) for(int  i = 0;i<n;i++)
using namespace std;

int maxlength(int arr[],int n){
    int maxs,mins;
    int maxlength = INT_MIN;
    for(int i = 0;i<n-1;i++){
        maxs = mins = arr[i];
        for(int j = i+1;j<n;j++){
            maxs = max(maxs,arr[j]);
            mins = min(mins,arr[j]);
            if(j-i == maxs - mins)
                maxlength = max(maxlength,j-i);
        }
    }
    return maxlength+1;
}
int main(){
    int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxlength(arr, n);
    return 0;
}
