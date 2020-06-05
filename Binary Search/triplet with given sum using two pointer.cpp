#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int arr[10004];
    int t,n,x;
    unordered_map<int,int> map;
    cin >> t;
    while(t--){
        //int count = 0;
        int flag = 0;
        cin >> n >> x;
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }

        sort(arr,arr+n);

        for(int i = 0;i<n-2;i++){
            int l = i+1;
            int r = n-1;

            while(l<r){
                if(arr[i]+arr[l]+arr[r] == x){
                    flag = 1;
                    break;
                }

                else if(arr[i]+arr[l]+arr[r] < x)
                    l++;
                else
                    r--;
            }
        }

        cout << flag << endl;

    }







}
