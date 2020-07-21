
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
        long long x;
        cin >> n >> x;
        vector<long long> arr(n);
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        ll previousSmall = 0;
        int pointer = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] >= x)
                break;
            pointer++;
            previousSmall++;


        }
        ll days = 0;
        
        ll ps = previousSmall;   
        for(int i = pointer;i<n;i++){
            if(arr[pointer] > x){
                while(arr[pointer] > x){
                    x = x*2;
                    days++;
                }
            }

            days++;
            if(x > arr[pointer])
                x = arr[pointer];
            x = x << 1;
        }
        ll previoust = days+pointer;
        if(pointer != 0){
            days = 0;
            pointer--;

        for(int i = pointer;i<n;i++){
            if(arr[pointer] > x){
                while(arr[pointer] > x){
                    x = x*2;
                    days++;
                }
            }

            days++;
            if(x > arr[pointer])
                x = arr[pointer];
            x = x << 1;
        }
        if(days+pointer < previoust)
            cout << days+pointer << endl;
        else
            cout << previoust << endl;
        }else
            cout << previoust << endl;

    }

    

    return 0;
}



