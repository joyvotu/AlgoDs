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
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
    
    vector<ll> a;
    for(int i = 0;i<n;i++){
        ll b;
        cin >> b;
        a.pb(b);
    }
    sort(a.begin(),a.end());
    ll maxEle = a[n-1];
    ll  days = 0;
    while(x < maxEle){
        for(int i = 0;i<n;i++){
            if(x > a[i]){
                x = a[i];
                x = x << 1;
                days++;
                a.erase(a.begin()+i);
                continue;
            }
            if(a[i] == x){
                x = x << 1;
                a.erase(a.begin()+i);
                break;
            }else{
                if(a[i] > x){
                    x = x << 1;
                    a[i] = a[i]-x;
                    a[i] = a[i]*2;
                    break;
                }

            }

        }
        days++;
        cout << x << endl;
        
    }
    cout << days+a.size() << endl;
    }

    return 0;
}




