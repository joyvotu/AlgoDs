#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int t;
    scanf("%d" , &t);
    while(t--){
        int n;
        scanf("%d" ,&n);
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n));
        for(int row = 0,col = 0;col<n; row++,col++){
            int temp;
            scanf("%d", &temp);
            dp[row][col].first = temp;
            dp[row][col].second = 0;
        }
        for(int gap = 1;gap<n;gap++){
            for(int row = 0,col = gap;col<n;col++,row++){
                int first = dp[row][row].first + dp[row+1][col].second;
                int second = dp[col][col].first + dp[row][col-1].second;
                if(first>second){
                    dp[row][col].first = first;
                    dp[row][col].second = dp[row+1][col].first;
                }else{
                    dp[row][col].first = second;
                    dp[row][col].second = dp[row][col-1].first;
                }
            }
        }
        cout << dp[0][n-1].first << endl;
    }
}
