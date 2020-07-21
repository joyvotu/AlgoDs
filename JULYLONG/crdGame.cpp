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
int sumOfDigits(int n){
    int ans = 0;
    while( n != 0){
        ans += n%10;
        n = n/10;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int chef = 0,morty= 0;
        for(int i = 0;i<n;i++){
            int a,b;
            cin >> a >>b;
            int c =  sumOfDigits(a);
            int d = sumOfDigits(b);
            if(c > d)
                chef++;
            else if(d > c)
                morty++;
            else if(d == c){
                chef++;
                morty++;
            }


        
        }
        if(chef > morty)
            cout << 0 << " " << chef << endl;
        else if(morty > chef)
            cout << 1 << " " << morty << endl;

        else if(morty == chef)
            cout << 2 <<  " " <<morty << endl;
    }

    return 0;
}




