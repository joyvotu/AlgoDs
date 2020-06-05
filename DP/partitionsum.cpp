#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int partitionSum(vector<int> &val,int size,int sum){
    vector<vector<bool>> dp(size,vector<bool>(sum+1));
    for(int row = 0;row<size;row++){
        for(int col = 0;col<=sum;col++){
            if(col == 0)
                dp[row][col] = 1;
            else if(row == 0){
                if(col == val[row])
                    dp[row][col] = 1;
            }else{
                if(col - val[row] >= 0)
                    dp[row][col] = dp[row-1][col] | dp[row-1][col-val[row]];
                else
                    dp[row][col] = dp[row-1][col];
            }
        }
    }


    int row = size-1;
    for(int col = sum ;col>=0;col--){
        if(dp[row][col])
            return col;
    }
    return 0;
}








int main(){

    int t;
    scanf("%d" ,&t);
    while(t--){
        int n;
        scanf("%d ",&n);
        vector<int> val(n);
        for(int i = 0;i<n;i++){
            cin >> val[i];
        }
        int sum = accumulate(val.begin(), val.end(), 0);
        int res = partitionSum(val,n,sum/2);
        cout << sum-(2*res) << endl;
    }

}
