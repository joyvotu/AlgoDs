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
        cin >> n;
        fr(i,n){
            cin >> arr[i];
        }
        string result = "No";
        int cursum = 0;

        fr(i,n){
            cursum += arr[i];
            if(cursum == 0){
                result  = "Yes";
                break;
            }

           else if(mp[cursum] > 0){
                result  = "Yes";
                break;
            }
            mp[cursum]++;
        }
        cout << result << endl;
        result = "No";
        mp.clear();

    }
    return 0;

}
