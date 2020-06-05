#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int missingElement(int arr[], int l,int r){
    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] == mid)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}



int main(){
    int arr[] = {0,1,2,3,4,6,7};
    cout << missingElement(arr, 0, 6);
}
