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



vector<ll> t;

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int findMax(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(findMax(v*2, tl, tm, l, min(r, tm))
           ,findMax(v*2+1, tm+1, tr, max(l, tm+1), r));
}
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
    ll n,query;

	cin>>n>>query;
    t.resize(4*n+1);
	ll hght[n];
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		hght[i] = a;
	}
    build(hght,1,0,n-1);
	vector<ll>tstiness;
	for(ll i=0;i<n;i++)
	{
		ll b;
		cin>>b;
		tstiness.push_back(b);
	}
	while(query--)
	{
		ll query_t, a,b;
		cin>>query_t>>a>>b;
		if(query_t==1)
		{
			tstiness[a-1]=b;
		}
		else{
			ll src=b-1;
			ll dest=a-1;
			if(src==dest)
			{
				cout<<tstiness[src]<<endl;
				continue;
			}
			if(hght[dest]<=hght[src])
			{
				cout<<-1<<endl;
				continue;
			}
			ll dir = 1;
            bool flg = true;
            ll maxHght;
            if(src > dest){
            maxHght = findMax(1,0,n-1,dest+1,src);
            
               
            dir = -1;
            
            }
            else{
                 maxHght = findMax(1,0,n-1,src,dest-1);
            }
            
            if(maxHght >= hght[dest])
                cout << -1 << endl;
            else{
               


			ll next=src+dir;
			ll curr=src;
			ll total=tstiness[src];
			ll flag=true;
			while(next!=dest)
			{
				if(hght[next]>hght[curr])
				{
					curr=next;
					total+=tstiness[curr];
				}
				next+=dir;
			}
				cout<<total+tstiness[dest]<<endl;
			}
		}
	}
	return 0;   

}




