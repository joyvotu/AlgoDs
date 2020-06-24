#include <bits/stdc++.h>
using namespace std;
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
set<int> cutpoints;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cutpoints.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cutpoints.insert(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cutpoints.clear();
        int m;
        cin >> n >> m;
        adj.clear();
        vector<int> a(n);
        vector<int> b(n);
        vector<double> c(n);
        long long total_a = 0;
        long long total_b = 0;
        for(int i = 0;i<n;i++){
            int z;
            cin >> z;
            a[i] = z;
            total_a += z;
        }
        for(int i = 0;i<n;i++){
            int w;
            cin >> w;
            b[i] = w;
            total_b += w;
        }
        adj.resize(n);
        for(int i = 0;i<m;i++){
            int x,y;
            cin >> x >> y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        find_cutpoints();
        vector<int> result;
        long double cur_income = total_a/total_b;
        for(int i = 0;i<n;i++){
            if(((total_a-a[i])/(total_b-b[i]) > cur_income) && cutpoints.find(i) == cutpoints.end())
                result.push_back(i);
        }

        cout << result.size() << endl;
        for(int x:result){
            cout << x+1 << " ";
        }
        cout << endl;
        
    }
 
}
