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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,int> mpx,mpy;
        for(int i = 0;i<4*n-1;i++){
            int x,y;
            cin >> x >> y;
            if(mpx[x] == 1)
                mpx.erase(x);
            else
                mpx[x]++;
            
            if(mpy[y] == 1)
                mpy.erase(y);
            else
                mpy[y]++;

        }
        int x1,y1;
        for(auto it = mpx.begin();it!= mpx.end();it++){
            if(it->second & 1){
                x1 = it->first;
                break;
            }
        }

        for(auto it = mpy.begin();it!= mpy.end();it++){
            if(it->second & 1){
                y1 = it->first;
                break;
            }
        }
        cout << x1 << " " << y1 <<  endl;
    }
    return 0;
}




