#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int id(int arr[],int lo,int high,int k){
    while(lo<=high){
        int mid = lo+((high-lo)/2);
        if(arr[mid] == k)
            return mid;
        if(arr[mid] <= arr[high]){
            //right sorted
            if(k>=arr[mid] && k <= arr[high])
                lo = mid+1;
            else
                high = mid-1; // else check left

        }
        else{
            //left is sorted
            if(k>=arr[lo] && k<=arr[mid]){
                high = mid-1;
            }else{
                lo = mid+1; //check right
            }
        }


    }
    return  -1;
}



int main(){
    int arr[] = {8,9,10,2,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << id(arr, 0, n-1,2);

}
