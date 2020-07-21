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

vector<vpi> adj(100);

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

vi d;
vector<bool> u;
void dijkstra(int n){
    d.assign(n+1,INT_MAX);
    u.assign(n+1,false);
    d[1] = 0;
    for(int i = 1;i<=n;i++){
        int v = -1;
        for(int j = 1;j<=n;j++){
            if(!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        if(d[v] == INT_MAX)
            break;
        u[v] = true;
        for(auto y : adj[v]){
            int to = y.first;
            int wt = y.second;
            if(d[v]+wt < d[to])
                d[to] = d[v]+wt;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int m,n;
    cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));

    }
    dijkstra(n);
long long c=1000000000;
    for(int i = 2;i<=n;i++){
        if(d[i] == INT_MAX)
            cout << c << " ";
        else
            cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}




