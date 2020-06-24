#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,b,m;
        cin >> n >> b >> m;
        set<int> lastblockelements;
        int lbsize = n%b;
        int lastBlockStarting = n/b;
        for(int i = lastBlockStarting*b;i<n;i++)
            lastblockelements.insert(i);

        int result = 0;
        vector<int> M(m);
        for(int i = 0;i<m;i++){
            int a;
            cin >> a;
            M[i] = a;
        }
        int curblock = -1;
        for(int i = 0;i<m;i++){
            if(result == 0){
                curblock = M[i]/b;
                result++;
            }else{
                if(curblock == M[i]/b){
                    continue;
                }else{
                    curblock = M[i]/b;
                    result++;
                }
            }
        }
        cout << result << endl;
            
    }
}
