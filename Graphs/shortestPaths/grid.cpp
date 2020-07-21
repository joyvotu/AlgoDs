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
vii grid(100,vector<int>(100));

void createGrid(int n,int m){
    grid.resize(n+1,vector<int>(m+1));
    int res = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            grid[i][j] = res++;
        }
    }

}
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
long long INF = 10000002;
vector<int> d;
vector<bool> u;
void dijkstra(int n,int s){
    set<pair<int,int>> q;
    d.assign(n+1,INF);
    d[s] = 0;
    q.insert({0,s});
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int to : adj[v]){
            if(d[v]+1 < d[to]){
                q.erase({d[to],to});
                d[to] = d[v] + 1;
                q.insert({d[to],to});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n,m,q;
    cin >> n >> m >> q;
    int size = (n+1)*(m+1);
    adj.resize(size);
    vector<vector<char>> matrix(n+1,vector<char>(m+1));
    for(int i = 1;i<=n;i++){
        string s;
        cin >> s;
        for(int j = 1;j<=m;j++){
            matrix[i][j] = s[j-1];
        }
    }

    createGrid(n,m);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(matrix[i][j] == 'O'){
                if(i-1 > 0 && matrix[i-1][j] == 'O')
                    adj[grid[i][j]].pb(grid[i-1][j]);

                if( j-1>0  && matrix[i][j-1] == 'O')
                    adj[grid[i][j]].pb(grid[i][j-1]);

                
                if(i+1 <= n && matrix[i+1][j] == 'O')
                    adj[grid[i][j]].pb(grid[i+1][j]);


                if( j+1<=m && matrix[i][j+1] == 'O')
                    adj[grid[i][j]].pb(grid[i][j+1]);
            }
            
        }
    }
    int s1,s2;
    cin >> s1 >> s2;
    int s = grid[s1][s2];
    dijkstra(size,s);
    while(q--){
        int x,y;
        cin >> x >> y;
        int t = grid[x][y];
        if(d[t] == INF)
            cout << -1 << endl;
        else
            cout << d[t] << endl;
    }
    
    
    return 0;
}




