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
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        unordered_map <ll,ll> mpt,mp1,mp2;
        ll minEl = INT_MAX;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            minEl = min(a[i],minEl);
            mpt[a[i]]++;
        }
        for(int i = 0;i<n;i++){
            cin >> b[i];
            minEl = min(b[i],minEl);
            mpt[b[i]]++;
        }
        bool flag = true;
        for(auto i:mpt){
            if(i.second & 1){
                flag = false;
                break;
            }else{
                mp1[i.first] = i.second/2;
            }
        }
        if(!flag){
            cout << -1 << endl;
        }else{
            mp2 = mp1;
            vector<ll> ans1,ans2;
            for(int i = 0;i<n;i++){
                if(mp1[a[i]])
                    mp1[a[i]]--;
                else
                    ans1.pb(a[i]);
            }
            for(int i = 0;i<n;i++){
                if(mp2[b[i]])
                    mp2[b[i]]--;
                else
                    ans2.pb(b[i]);
            }
            sort(ans1.begin(),ans1.end());
            sort(ans2.begin(),ans2.end());
            ll cost1 = 0,cost2 = 0;
            if(ans1.size() != ans2.size())
                cout << -1 << endl;
            else if(ans1.size() == 0)
                cout << 0 << endl;
            else{
                for(int i = 0,j=ans2.size()-1;i<ans1.size();i++,j--){
                    cost1 += min(2*minEl,min(ans1[i],ans2[j]));
                }
                    
                for(int i = 0,j=ans2.size()-1;i<ans1.size();i++,j--){
                    cost2 += min(2*minEl,min(ans2[i],ans1[j]));
                }
                cout << min(cost1,cost2) << endl;
            }

        }















    }

    return 0;
}




