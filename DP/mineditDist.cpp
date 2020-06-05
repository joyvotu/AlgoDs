#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string s1,s2;
//for solving by brute force
int minEdit(int m,int n){
    if(m+1 == 0)
        return n+1;
    if(n+1 == 0)
        return m+1;
    if(s1[m] == s2[n])
        return minEdit(m-1,n-1);
    else
        return min(min(minEdit(m-1,n),minEdit(m,n-1)),minEdit(m-1,n-1))+1; // for dlt,insert,replace;
}


int dpsolve(int firstSize,int secondSize){
    //first string in row,second string in col
    vector<vector<int>> dp(firstSize, vector<int>(secondSize,0));
    for(int row = 0;row<firstSize;row++){
        for(int col = 0;col<secondSize;col++){
            if(row == 0 && col == 0)
                dp[row][col] = 0;
            else if(row == 0)
                dp[row][col] = col;
            else if(col == 0)
                dp[row][col] = row;
            else{
                if(s1[row] == s2[col])
                    dp[row][col] = dp[row-1][col-1];
                else
                    dp[row][col] = min(min(dp[row-1][col],dp[row][col-1]),dp[row-1][col-1])+1;
            }
        }
    }
    return dp[firstSize-1][secondSize-1];

}
int main() {
    int t;
    scanf("%d" ,&t);
    while(t--){
        s1 = "";
        s2 = "";
        int p,q;
        scanf("%d %d",&p , &q);
        string temp1 , temp2;
        cin >> temp1 >> temp2;
        s1 = "X"+temp1;
        s2 = "Y"+temp2;
        cout << dpsolve(int(s1.size()),int(s2.size())) << endl;
    }
    return 0;
}
