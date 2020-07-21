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
        vector<ll> arr;
        for(int i = 0;i<n;i++){
            ll a;
            cin >> a;

            arr.pb(a);
        }
        sort(arr.begin(),arr.end());
        
        ll small = 0;
        ll ptr = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] >= x)
                break;
            small++;
            ptr++;
        }
        ll days = 0;
        while(ptr < n){

            while(arr[ptr]/2 > x){
                cout << x << " " << arr[ptr] << endl;
                x = x << 1;
                days++;
            }

            cout << x << " " << arr[ptr] << endl;
           if(x >= arr[ptr]){

                x = arr[ptr];
                cout << " --- " << x << " " << arr[ptr] << endl;
           }
           else{

              small++;
              cout << "change in" << " " << ptr << endl;
           }

          days++;
          ptr++;
          x = x << 1;

        }
        days--;
        cout << days+small << endl;





    }
    

    return 0;
}




