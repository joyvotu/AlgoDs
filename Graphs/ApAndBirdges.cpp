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
vector<int> tin,low;
vector<bool> vis;
int timer;
vector<int> ap;
vector<pair<int,int>> bridges;
void dfs_ap(int v,int p = -1){
    vis[v]=1;
    tin[v] = low[v] = timer++;
    int children = 0;
    for(int to: adj[v]){
        if(to == p)continue;
        if(vis[to]){
            low[v] = min(low[v],tin[to]);
        }else{
            dfs_ap(to,v);
            low[v] = min(low[v],low[to]);
            if(low[to]>= tin[v] && p != -1)
                ap.pb(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        ap.pb(v);
}
void dfs_apUtil(int n){
    int timer = 0;
    vis.assign(n,false);
    tin.assign(n,-1);
    low.assign(n,-1);
    for(int i = 0;i < n;i++){
        if(!vis[i])
            dfs_ap(i);
    }
}

void dfs_bridges(int v,int p = -1){
    vis[v]=1;
    tin[v] = low[v] = timer++;
    for(int to: adj[v]){
        if(to == p)continue;
        if(vis[to]){
            low[v] = min(low[v],tin[to]);
        }else{
            dfs_bridges(to,v);
            low[v] = min(low[v],low[to]);
            if(low[to]> tin[v]){
                if(v > to)
                    bridges.pb(mp(to,v));
                else
                    bridges.pb(mp(v,to));
            }
        }
    }
}
void dfs_bridgesUtil(int n){
    int timer = 0;
    vis.assign(n,false);
    tin.assign(n,-1);
    low.assign(n,-1);
    for(int i = 0;i < n;i++){
        if(!vis[i])
            dfs_bridges(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n,m;
    cin >> n >> m;
    ipgraph(m,n);
    dfs_apUtil(n);
    dfs_bridgesUtil(n);
    sort(ap.begin(),ap.end());
    sort(bridges.begin(),bridges.end());
    cout << ap.size() << endl;
    printvi(ap);
    cout << bridges.size() << endl;
    for(int i = 0;i<bridges.size();i++){
        cout << bridges[i].first << " " << bridges[i].second << endl;
    }
    

    return 0;
}




