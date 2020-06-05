#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int n;
    scanf("%d" , &n);
    vector<int> wine(n);
    for(int i = 0;i<n;i++){
        cin >> wine[i];
    }
    vector<vector<int>> dp(n,vector<int> (n));
    int y = n;
    for(int gap = 0;gap<n;gap++){
        for(int row=0,col=gap;col<n;row++,col++){
            if(row == col)
                dp[row][col] = y*wine[row];
            else{
                dp[row][col] = max(y*wine[row]+dp[row+1][col],y*wine[col]+dp[row][col-1]);
            }
        }
        y--;
    }
    cout << dp[0][n-1] << endl;
}
