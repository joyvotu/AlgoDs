#include <bits/stdc++.h>
typedef long long ll;


using namespace std;
typedef vector<pair<int,int>> vii;


#define fr(i,n) for(int i = 0;i<n;i++)
//number of ways to reach nth stair given you can only move 1 or two steps at a time give for 0 and 1 , it is 1; special case, max k jumps allowed;


int dp[100005][10009]; // jumps,stairs

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0;i<=k;i++)
        dp[i][0] = 1;
    for(int i = 1;i<=k;i++)
        dp[i][1] = 1;
    dp[1][2] = 1;

    for(int i  = 1;i<=k;i++){
        for(int j = 2;j<=n;j++){
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j-2];
        }
    }

    for(int i = 0;i<=k;i++){
        for(int j = 0;j<=n;j++)
            cout << dp[i][j] << "\t";

        cout << endl;
    }

    cout << dp[n][k];
}
