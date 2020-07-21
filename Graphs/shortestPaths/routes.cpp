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
#define pi pair<int,int> 
vector<vector<pair<int,pi>>> adj;
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
long long INF = 1000000009;
vector<int> d;
vector<int> p;
vector<int> ti;
int dijkstra(int n,int s,int k,int t){
    d.assign(n+1,INF);
    p.assign(n+1,-1);
    ti.assign(n+1,0);
    d[s] = 0;
    ti[s] = 0;
    set<pi> q;
    q.insert({0,s});
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto y: adj[v]){
            int to = y.first;
            int wt = y.second.second;
            int time  = y.second.first;
            if(to != t){
                if(d[v]+wt+k < d[to] ){
                    
                q.erase({d[to],to});
                d[to] = d[v]+wt+k;
                p[to] = v;
                ti[to] = ti[v]+time+1;
                q.insert({d[to],to});
                }
            }else{
                if(d[v]+wt < d[to]){
                    q.erase({d[to],to});
                     d[to] = d[v]+wt;
                     p[to] = v;
                     ti[to] = ti[v]+time;
                    q.insert({d[to],to});
                }
            }
        }
    }
    return d[t];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int k;
    int m,n;
    cin >> k >> n >> m;
    unordered_map<string,int> mpp;
    adj.resize(n+1);
    bool fl = true;
    for(int i = 0;i<m;i++){
        int a,b,t,w;
        cin >> a >> b >> t >> w;
        int wt = t*k+w;
        adj[a].pb(mp(b,mp(t,wt)));
        adj[b].pb(mp(a,mp(t,wt)));
        string str = to_string(a)+" "+to_string(b);
        if(mpp.find(str)!=mpp.end())
            fl = false;

        mpp[str]++;
    }
    int s,t;
    cin >> s >> t;
    int ans = dijkstra(n,s,k,t);
    vi route;
    if(!fl){
        cout << "Error" << endl;
        return 0;
    }
    if(ans != INF){
    int time = 0;
    for(int i = t;i!=s;i = p[i]){
        route.pb(i);
    }
    
    cout << s << "->";
    reverse(route.begin(),route.end());
    int count = 0;
    for(int x : route){
        
        if(count == route.size()-1)
            cout << x << " ";
        else
            cout << x << "->" ;
        count++;
        
    }
    cout << ti[t] << " ";
    cout << ans << endl;
    }else{
        cout << "Error" << endl;
    }

    return 0;
}




