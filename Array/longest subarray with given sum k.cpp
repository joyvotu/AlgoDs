#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,n) for(int  i = 0;i<n;i++)
using namespace std;

int main(){
    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int arr[n+2];
        fr(i,n)
        cin >> arr[i];
        unordered_map<int,int> mp;
        int cursum = 0;
        int maxlen = 0;
        fr(i,n){
            cursum += arr[i];
            if(cursum == k)
                maxlen = i+1;
            if(mp.find(cursum) == mp.end()){
                mp[cursum] = i;
            }
            if(mp.find(cursum-k) != mp.end()){
                maxlen = max(maxlen,i - mp[cursum-k]);
                cout << mp[cursum-k] << " " << i;
            }


        }
        cout<< maxlen << endl;
    }
}
