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
        adj[b].pb(a);
    }
}
vector<bool> vis;
vector<int> lst,components;
vii adjr(5000);
void dfs1(int v){
    vis[v] = true;
    for(int to : adj[v]){
        if(!vis[to])
            dfs1(to);
    }
    lst.pb(v);
}
void dfs2(int v){
    vis[v] = true;
    components.push_back(v);
    for(int to : adjr[v]){
        if(!vis[to]){
            dfs2(to);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    adjr.resize(n+1);
    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adjr[y].pb(x);
    }
    vis.assign(n+1,false);
    lst.clear();
    for(int i = 1;i<=n;i++){
        if(!vis[i])
            dfs1(i);
    }
    
    int C = 0;
    int D = 0;
    vis.assign(n+1,false);
    for(int i = 0;i<lst.size();i++){
        int v = lst[n-1-i];
        if(!vis[v]){
            dfs2(v);
            int no = components.size();
            if(no&1)
                C+=no;
            else
                D+=no;
            components.clear();
        }
    }
    cout << C-D << endl;
    
    return 0;
}




