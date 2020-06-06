//Dijkstra is mainly based on bfs in a graph
//In c++ we use priority queue as min heap to represent the que and to get the shortest distance
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
void dijkstra(vector<vector<pii>> g,int n,int src){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<int> d(n+1,INT_MAX);
    d[src] = 0;
    q.push(make_pair(0,src));
    while(!q.empty()){
        pii cur = q.top();
        q.pop();
        int u = cur.second;
        for(auto x:g[u]){
            int v = x.first;
            int w = x.second;
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                q.push(make_pair(d[v],v));
            }
        }
    }
    for(int  i = 2;i<=n;i++){
        cout << d[i] << " ";
    }
    cout << "\n";
}
int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<pii>> g(v+1);
    for(int i = 0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
    }
    dijkstra(g,v,1);
}
