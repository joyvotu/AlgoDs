#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int t;
    scanf("%d" ,&t);
    while(t--){
        int n;
        scanf("%d" ,&n);
        int w;
        scanf("%d" ,&w);
        vector<int> weigh(n+1);
        vector<int> value(n+1);
        for(int i = 1; i<=n;i++)
            cin >> value[i];
        for(int i = 1;i<=n;i++)
            cin >> weigh[i];
        vector<int> dp(w+1);
        for(int i = 1;i<=w;i++){
            //int maxP = dp[i];
            for(int j = 1;j<=n;j++){
                if(i-weigh[j] >= 0){
                    if(value[j]+dp[i-weigh[j]] > dp[i])
                        dp[i] =value[j]+dp[i-weigh[j]];
                }
            }
        }
        cout << dp[w] << endl;
    }
}
