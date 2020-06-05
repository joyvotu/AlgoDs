//Given an array, each element represents the max no of jumps that can be done form that position
//Task is to reach the end of the array with min no jumps
#include <bits/stdc++.h>
using namespace std;
int dp[10000007];
int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int val[n+1];
        val[0] = -1;
        for(int i = 1;i<=n;i++){

            scanf("%d" , &val[i]);

        }
        dp[1] = 0;
        for(int i = 2;i<=n;i++){
            dp[i] = INT_MAX;
        }

        for(int i = 1;i<=n;i++){
            for(int x = 1;x<=val[i];x++){
                if(i+x <= n && dp[i] != INT_MAX)
                    dp[i+x] = min(dp[i]+1,dp[i+x]);
            }
        }

       if(dp[n] == INT_MAX)
           printf("-1\n");
        else
            printf("%d\n",dp[n]);
    }


}
