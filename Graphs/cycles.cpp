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
vector<int> color;
vector<int> parent;
int cycleStat, cycleEnd;
bool dfs(int v){
    color[v] = 1;
    for(int to:adj[v]){
        if(to == parent[v])continue;
        if(color[to] == 0){
            parent[to] = v;
           if(dfs(to))
               return true;
        }if(color[to] == 1){
            cycleStat = to;
            cycleEnd = v;
            cout << cycleStat << " " << cycleEnd << endl;
            return true;
        }
    
    }
    color[v] = 2;
    return false;
}
void checkCycles(int n){
    color.assign(n+1,0);
    parent.assign(n+1,-1);
    cycleStat = -1;
    for(int i = 0;i<n;i++){
        if(color[i] == 0 && dfs(i))
            break;
    }

    if(cycleStat == -1)
        cout << " NO CYCLES " << endl;
    else{
        vi cycles;
        cycles.pb(cycleStat);
        for(int v = cycleEnd;v!=cycleStat; v = parent[v]){
            cycles.pb(v);
        }
        printvi(cycles);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n,m;
    cin >> n >> m;
    ipgraph(m,n);
    checkCycles(n);


    return 0;
}




