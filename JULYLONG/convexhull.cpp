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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    vector<pair<double,int>>  points;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        double dist = sqrt(x*x + y*y);
        points.pb(mp(dist,i+1));

    }
    sort(points.begin(),points.end());
    for(int i = 0;i<n;i++){
        cout << points[n-1-i].second << " " ;
    }
    cout << endl;

    

    return 0;
}




