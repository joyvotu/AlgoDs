#include <bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>> 
#define vi vector<int>
#define ll long long
#define ld Long Double
#define vpi vector<pair<int,int>> 
#define mp make_pair
#define pb push_back
#define umap unordered_map<int,int> 

vii adj(10000);
struct edge{
    int a,b,cost;
};

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
void bellman(vector<edge> e,int n){
    vector<int> d(n+1,INT_MAX);
    d[1] = 0;
    int x;
    vector<int> p(n+1,-1);
    for(int i = 0;i<n;i++){
        x = -1;
        for(int j = 0;j<e.size();j++){
            if(d[e[j].a] < INT_MAX){
            if(d[e[j].b] > d[e[j].a]+e[j].cost){
                d[e[j].b] = max(INT_MIN,d[e[j].a]+e[j].cost);
                p[e[j].b] = e[j].a;
                x = e[j].b;
            }
            }

        }
    }

    if(x == -1)
        cout << "no negative cycles" << endl;
    else{
        int y = x;
        cout << y << endl;
        for(int i = 0;i<n;i++){
        
            y = p[y]; 
            cout << y << endl;
        }
        vector<int> path;
        
        for(int cur = y; ; cur = p[cur]){
            if(cur == y && path.size() > 1){
                break;
            }       
            path.pb(cur);
        }
        reverse(path.begin(),path.end());
        printvi(path);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n, e;
    cin >> n >> e;
    vector<edge> liste(e);
    int i = 0;
    while(e--){
        int a,b,cost;
        cin >> a >> b >> cost;
        liste[i].a = a;
        liste[i].b = b;
        liste[i].cost = cost;
        i++;
    }    
    bellman(liste,n);
    return 0;
}




