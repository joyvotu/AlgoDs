#include <bits/stdc++.h>
using namespace std;
long long pow(long long x,long long y){

    long long res = (long long)1;
    while(y>0){
        if(y&1){
            res = res*x;
        }
        y = y >> 1;
        x = x*x;
        
    }
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long  ts = n;
        if(n&1){
            cout << n/(long long)2 << endl;
        }else{
            long long nooftimes = 0;
            while(!(n&1)){
                n = n/(long long)2;
                nooftimes++;
            }
            long long  base = pow((long long)2,nooftimes+1);
            long long ans = ts/base;
            cout << ans << endl;
        }
    }
}
