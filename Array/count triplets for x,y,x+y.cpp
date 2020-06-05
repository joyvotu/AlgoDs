#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,n) for(int  i = 0;i<n;i++)
using namespace std;


int main(){
    int arr[] = {1, 1, 1, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = 0;
    //case 1 -> 0 + 0 = 0  so ---> f(0)c3 = f(0)*f(0)-1*f(0)-2/6
    // case 2 -> 0 + x = x so ---> f(x)c2*f(0) = f(x)*f(x)-1/ * f(0)/2
    //case 3 -> x + x = 2x  so --> f(x)c2*f(2x) = f(x)*f(x)-1/ * f(x)/2
    // case 4 -> x+y = x+yso --> f(x)*f(y)*f(x*y)

    unordered_map<int, int> mp;

    fr(i,n){
        mp[arr[i]]++;
    }
    ans += mp[0]*(mp[0]-1)*(mp[0]-2)/6;
    fr(i,n){
        ans+= mp[i]*(mp[i]-1)*mp[0]/2;
    }
    fr(i,n){
        ans+= mp[i]*(mp[i]-1)*(mp[2*i])/2;
    }
    fr(i,n-1){
        for(int j=i+1;j<n;j++) {
            ans+= mp[i]*mp[j]*mp[i+j];
        }
    }
    cout << ans;









}
