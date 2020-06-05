
#include <bits/stdc++.h>
using namespace std;
bool dp[1005][1005];
int main() {
    int n,sum;
    vector<int> val;
    cin >> n >> sum;
    for(int i = 0;i<n;i++){
        int a;
        cin >> a;
        val.push_back(a);
    }
    sort(val.begin(),val.end());
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=sum;j++){
            if(j==0)
                dp[i][j] = 1;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=sum;j++){
            if(i == 0){
                if(val[i] == j)
                    dp[i][j] = 1;
            }else{
                if(j-val[i] >= 0)
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-val[i]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n-1][sum];


}
