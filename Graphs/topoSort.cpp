#include <bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>> 
#define vi vector<int>
#define ll Long Long
#define ld Long Double
#define vpi vector<pair<int,int>> 
#define mp make_pair
#define pb push_back
#define umap unordered_map<int,int> 

vii adj(10000);

void printvi(vector<int> a){
    for(int x: a){
        cout << x  << " ";
    }
    cout << endl;
}
void printvii(vii a){
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[i].size();j++){
            cout << a[i][j] << " " ;

        }
        cout << endl;
    }
}
void ipgraph(int m,int n){
    adj.clear();
    adj.resize(n+5);
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }
}
vector<bool> vis;
vi lst;
void dfs(int v){
    vis[v] = true;
    for(int to : adj[v]){
        if(!vis[to])
            dfs(to);
    }
    lst.pb(v);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n,m;
    cin >> n >> m;
    ipgraph(m,n);
    //sorting in reverse order
    for(int i = 1;i<=n;i++){
        sort(adj[i].rbegin(),adj[i].rend());
    }
    vis.assign(n+1,false);
    for(int i = 1;i<=n;i++){
        if(!vis[i])
            dfs(i);
    }
    reverse(lst.begin(),lst.end());
    printvi(lst);

    return 0;
}




