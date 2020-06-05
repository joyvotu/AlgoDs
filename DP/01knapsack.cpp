#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int t;
    scanf("%d" ,&t);
    while(t--){
        int n;
        scanf("%d" ,&n);
        int w;
        scanf("%d" ,&w);
        vector<int> weigh(n+1);
        vector<int> value(n+1);
        for(int i = 1; i<=n;i++)
            cin >> value[i];
        for(int i = 1;i<=n;i++)
            cin >> weigh[i];
        vector<vector<int>> dp(n+1,vector<int>(w+1));
        for(int row = 1;row<n+1;row++){
            for(int col = 1;col<w+1;col++){
                if(col-weigh[row] >= 0){
                    dp[row][col] = max(dp[row-1][col],value[row]+dp[row-1][col-weigh[row]]);
                }else{
                    dp[row][col] = dp[row-1][col];
                }
            }
        }

        cout << dp[n][w]<<endl;
    }
}
