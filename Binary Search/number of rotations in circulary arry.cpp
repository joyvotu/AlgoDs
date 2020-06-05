#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int numofr(int arr[],int lo,int high){
    while(lo<=high){
        if(arr[lo] <= arr[high])
            return lo;
        int mid = lo+((high-lo)/2);

        int prev  = (mid-1+high)%(high+1);
        int next = (mid+1)%(high+1);

        if(arr[mid] <= prev && arr[mid]<=next)
            return mid;
        else if(arr[mid] >= arr[lo])
            lo = mid+1;
        else if(arr[mid] <= arr[high] )
            high = (mid-1);

    }
    return -1;
}



int main(){
    int arr[] = {8,9,10,2,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << numofr(arr, 0, n-1);

}
