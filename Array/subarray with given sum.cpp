#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,n) for(int  i = 0;i<n;i++)
using namespace std;

int main(){
    int t,n,x;
    cin >> t;
    ll arr[10005];
    unordered_map<int,int> mp;

    while(t--){
        cin >> n ;
        fr(i,n){
            cin >> arr[i];
        }
        cin >> x;
        int cursum = 0,count = 0;

        fr(i,n){
            cursum += arr[i];
            if(cursum == x)
                count++;
            if(mp.find(cursum-x) != mp.end()){
                count += mp[cursum-x];
            }
            mp[cursum]++;
        }
        cout << count << endl;
        mp.clear();
    }
    return 0;

}
