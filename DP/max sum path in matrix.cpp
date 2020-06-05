#include <bits/stdc++.h>
typedef long long ll;

//allowed moves are down,down left,down right
using namespace std;
typedef vector<pair<int,int>> vii;


#define fr(i,n) for(int i = 0;i<n;i++)

int val[24][24];
int dp[24][24];
int maxi(int a,int b,int c){
    if(a > b){
        if(a > c)
            return a;
        else
            return c;
    }
    else if(b > c)
        return b;
    else
        return c;

}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        fr(i,n)
            fr(j,n)
                cin >> val[i][j];

        fr(i,n)
            dp[0][i] = val[0][i];

        for(int i =1;i<n;i++){
            fr(j,n){
                if(j == 0)
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j+1])+val[i][j];
                else if(j == n-1)
                    dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+val[i][j];
                else
                    dp[i][j] = maxi(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+val[i][j];
            }
        }
        int m = INT_MIN;
        for(int j = 0;j<n;j++){
            if(dp[n-1][j]>m)
                m = dp[n-1][j];
        }
        cout << m << endl;

    }


}
