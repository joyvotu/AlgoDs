#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,n) for(int  i = 1;i<n;i++)
using namespace std;


int lcsubstring(string x,string y,int m,int n){
    int maxlength = 0;
    int dop[m+1][n+1];
    memset(dop,0,sizeof(dop));
    fr(i,m+1){
        fr(j,n+1){
          if(x[i-1] == y[j-1])
              dop[i][j] = dop[i-1][j-1] + 1;
          if(maxlength < dop[i][j])
              maxlength = dop[i][j];
        }
    }
    return maxlength;
}
int main(){
    int t,m,n;
    cin >> t;
    while(t--){
        cin >> m >> n;
        string x,y;
        cin >> x;
        cin >> y;
        cout << lcsubstring(x, y, m, n) << endl;
    }

}
