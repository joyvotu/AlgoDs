#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        int ans = 0;
        for(int i = 0;i<n;i++){
            int b;
            cin >> b;
            a[i]=b;
            if(b > k)
                ans+= b-k;
        }
        cout << ans << "\n"; 
    }
}
