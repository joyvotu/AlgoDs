#include <bits/stdc++.h>
#define scani(a) scanf("%d" ,&a)
#define scanl(a) scanf("%lld", &a)
using namespace std;
long long cur_res = 0;
vector<vector<int>> g(200005);
vector<long long> ar(200005);
vector<bool> vis(200005);
long long dfs(int s){
    vis[s] = true;
    long long res = ar[s];
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        for(int x: g[cur]){
            if(!vis[x]){
                st.push(x);
                res += ar[x];
                vis[x] = true;
            }
        }
    }
    return res;
}
void dfsUtil(int n){
    long long result = 0;
    for(int i = 1;i<=n;i++){
        if(!vis[i] ){
            result = max(dfs(i),result);
        }
    }
    cout << result << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        scani(n);
        scani(m);
        g.clear();
        vis.clear();
        ar.clear();
        g.resize(n+5);

        ar.resize(n+5);
        vis.resize(n+5);
        for(int i = 0;i<m;i++){
            int a,b;
            scani(a);
            scani(b);
            g[a].push_back(b);
            
            g[b].push_back(a);
        }
        for(int i = 1;i<=n;i++){
            long long x;
            scanl(x);
            ar[i] = x;
        }

        dfsUtil(n);
    }
}
