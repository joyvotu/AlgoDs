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
        map<int,int> mp;
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        bool flag = true;
        vector<int> result;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second>0){
                result.pb(it->first);
                mp[it->first]--;
            }
        }
        auto it1 = mp.rbegin();
        if(it1->second > 0)
            flag = false;
        if(flag){
        for(auto it = mp.rbegin();it!=mp.rend();it++){
            if(it->second > 0 ){
                result.pb(it->first);
                mp[it->first]--;
            }
        
        }
        }
        if(flag){
        for(auto it = mp.begin();it!= mp.end();it++){
            if(it->second > 0){
                flag = false;
                break;
            }
        }
        }
        if(!flag)
            cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            printvi(result);
        }
    }
    

    return 0;
}




