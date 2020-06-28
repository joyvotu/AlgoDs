#include <bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>> 
#define vi vector<int>
#define vpi vector<pair<int,int>> 
#define mp make_pair
#define pb push_back
#define umap unordered_map<int,int> 
typedef long long ll;
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
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            sum |= a[i];
        }
        int temp = sum;
        vector<int> mask;
        while(sum != 0){
            mask.pb(sum%2);
            sum = sum/2;
            
        
        }
        ll accm = 0;
        ll cur = 0;
        int s = mask.size();
        vector<int> tbitnumbers;
        int number1 = 1;
        int number2 = 1;
        int x = mask.size();
        int y = mask.size();
        while(number1 < temp){
             number2 = number1 << 1;
            while(number2 < temp){
            
                tbitnumbers.pb(number2|number1);
                number2 = number2 << 1;    
            }
            number1 = number1 << 1;
        }
        
        printvi(tbitnumbers);

        if(k == 1){
            int number = 1;
            int result = 1;
            while(s--){
                cur = 0;
                for(int i = 0;i<n;i++){
                    cur += ll(a[i]&number);
                }
                if(cur > accm){
                    accm = cur;
                    result = number;
                }

                number = number << 1;
            }
            cout << result << endl;
        }else if(k == 2){
            s = mask.size();
            accm = 0;
            cur = 0;
            int number = 3;
            int result = 3;
             for(int number : tbitnumbers){
                for(int i = 0;i<n;i++){
                    cur += ll(a[i]&number);
                }
                if(cur > accm){
                    accm = cur;
                    result = number;
                }


            }
            cout << result << endl;
        }


    }
    

    return 0;
}




