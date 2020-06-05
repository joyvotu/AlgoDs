#include <bits/stdc++.h>
typedef long long ll;


using namespace std;
typedef vector<pair<int,int>> vii;


#define fr(i,n) for(int i = 0;i<n;i++)



int dp[1000006];
int c[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
int main(){

    int t;
    cin >> t;
    while(t--){
        unordered_map<int,vector<int>> mp;
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++)
            dp[i] = INT_MAX;
        while(n > 2000){
            for(int i = 0;i<n/2000;i++)
                cout << 2000 << " ";
            n = n%2000;
        }

        for(int i  =1;i<=n;i++){
            for(int j = 0;j<9;j++){
                int x  = c[j];
                if(i-x >= 0){
                    if(dp[i-x] != INT_MAX){
                        if(dp[i-x]+1 < dp[i]){
                            dp[i] = dp[i-x]+1;
                            mp[i].clear();
                            mp[i].push_back(x);
                            copy(mp[i-x].begin(), mp[i-x].end(), back_inserter(mp[i]));
                        }
                    }
                }

            }
        }
        sort(mp[n].begin(),mp[n].end(),greater<int>());
        for(auto it = mp[n].begin();it!= mp[n].end();it++)
            cout << *it << " ";

        cout << endl;
    }

}
