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
void printSt(stack<pair<int,int>> st){
    while(!st.empty()){
        cout << st.top().first << " " << st.top().second << endl;
        st.pop();
    }
}
vector<int> tin,low;
vector<bool> vis;
int timer;
int even = 0;
int odd = 0;
stack<pair<int,int>> st;
void dfs_ap(int v,int p = -1){
    vis[v] = true;
    low[v] = tin[v] = timer++;
    int child = 0;
    for(int to : adj[v]){
        if(!vis[to]){
            child++;
            st.push(mp(to,v));
            dfs_ap(to,v);
            low[v] = min(low[v],low[to]);
            if(p == -1 && child > 1){
                while(st.top().first != to &&  st.top().second != v){
                    cout << st.top().first << " " << st.top().second << endl;
                    st.pop(); 
                }

            cout << st.top().first << " " << st.top().second << endl;
            st.pop();
            }
            else if(low[to] >= tin[v] && p != -1){

                while(st.top().first != to &&  st.top().second != v){
                    cout << st.top().first << " " << st.top().second << endl;
                    st.pop(); 
                }

            cout << st.top().first << " " << st.top().second << endl;
            st.pop();
            }
        }
        else if(to != p && tin[to]<low[v]){
            low[v] = tin[to];
            st.push(mp(to,v));
        }
    }
    
}
void dfsUtil(int n){
    timer = 0;
    vis.assign(n+1,false);
    tin.assign(n+1,-1);
    low.assign(n+1,-1);
    for(int i = 0;i<n;i++){
        if(!vis[i])
            dfs_ap(i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int m,n;
    cin >> n >> m;
    ipgraph(m,n);
    dfsUtil(n);
    

    return 0;
}




