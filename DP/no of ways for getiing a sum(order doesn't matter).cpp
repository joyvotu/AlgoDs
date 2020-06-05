
#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int main() {
    int t,n,sum,a;

    scanf("%d ",&t);
    while(t--){
        vector<int> coins;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            scanf("%d ",&a);
            coins.push_back(a);
        }
        scanf("%d" , &sum);
        sort(coins.begin(),coins.end());

        for(int i = 0;i<n;i++){
            for(int j = 0;j<sum+1;j++){
                if(j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 1;j<sum+1;j++){
                if(i == 0){
                    if(j-coins[i] >= 0)
                        dp[i][j] = dp[i][j-coins[i]];
                }else{
                    if(j-coins[i] >= 0)
                        dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }

        printf("%d\n", dp[coins.size()-1][sum]);

    }
}
