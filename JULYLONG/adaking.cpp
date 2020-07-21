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
        
        vector<vector<char>> board(8,vector<char>(8));
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                board[i][j] = '.';
            }
        }
        board[7][7] = 'O';
        int k;
        cin >> k;
        int left = 64-k;
        int count = 0;
        
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if(count == left)
                    break;
                board[i][j] = 'X';
                count++;
            }
            if(count == left)
                break;
        }


        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                cout << board[i][j];
            }
            cout << endl;
        }

    }
    

    return 0;
}




