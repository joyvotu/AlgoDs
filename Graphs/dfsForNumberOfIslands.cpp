#include <bits/stdc++.h> 
using namespace std;
void dfscalc(vector<vector<bool>>& mati,int m,int n,int s1,int s2){
    stack<pair<int,int>> s;
    s.push(make_pair(s1,s2));
    mati[s1][s2] = 0;
    while(!s.empty()){
        pair<int,int> cur = s.top();
        s.pop();
        for(int i = cur.first-1;i<=cur.first+1;i++){
            for(int j = cur.second-1;j<=cur.second+1;j++){
                if(i>=0 && i <m && j >=0 && j<n){
                    if(mati[i][j]){
                         s.push(make_pair(i,j));
                         mati[i][j]=0;
 
                    }
                }
            }
        }
    }

}
int dfs(vector<vector<bool>>& mati,int m,int n  ){
    int ans = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(mati[i][j]){
                dfscalc(mati,m,n,i,j);
                ans++;
            }
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        vector<vector<bool>> mati(m,vector<bool>(n));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int a;
                cin >> a;
                if(a==1)
                    mati[i][j]=1;
            }
        }
        cout << dfs( mati, m, n) << "\n";

     }


}
