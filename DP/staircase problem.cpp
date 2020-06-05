#include <bits/stdc++.h>
typedef long long ll;


using namespace std;
typedef vector<pair<int,int>> vii;


#define fr(i,n) for(int i = 0;i<n;i++)
//number of ways to reach nth stair given you can only move 1 or two steps at a time give for 0 and 1 , it is 1;



int main(){
    int dp[100005];
    dp[0] = 1;
    dp[1] = 1;
    int n;
    cin >> n;
    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    cout << dp[n];
}
