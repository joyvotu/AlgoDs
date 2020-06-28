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
        int s,n;
        cin >> s >> n;
        int result = 0;
        if(s&1)
           result = 1;
        if(s <= n){
            if(s == 1)
                cout << 1 << endl;
            else
                cout << 1+result << endl;

        }else{
            if(s % n == 0)
                cout << s/n << endl;
            else if(s % n == 1)
                cout << s/n+1 << endl;
            else if(s % n > 1){
                if((s%n)&1)
                    cout << s/n + 2 << endl;
                else
                    cout << s/n +1 << endl;
            }
        }
    }
    

    return 0;
} 




