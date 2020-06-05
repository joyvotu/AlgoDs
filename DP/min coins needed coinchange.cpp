#include <bits/stdc++.h>
typedef long long ll;


using namespace std;
typedef vector<pair<int,int>> vii;


#define fr(i,n) for(int i = 0;i<n;i++)



int dp[1000006] ;
int c[1000006];
int main(){

    int t,v,n;
    cin >> t;
    while(t--){
        cin >> v >> n;
        fr(i,v+1)
            dp[i] = INT_MAX;
        fr(i,n)
            cin >> c[i];
        dp[0] = 0;
        for(int i = 1;i<=v;i++){
            for(int j = 0;j<n;j++){
                if(i-c[j]>=0)
                    if(dp[i-c[j]] != INT_MAX)
                    dp[i] = min(dp[i],dp[i-c[j]]+1);
            }
        }


        if(dp[v] == INT_MAX)
            cout << -1 << endl;
        else
            cout << dp[v] << endl;

    }

    return 0;


}
