#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> a;
        int count = 0;
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            if(x == m)
                count++;
            a.push_back(x);
        }
        vector<bool> check(m,false);
        check[0] = true;
        for(int i = 0;i<n;i++){
            if(a[i] < m)
                check[a[i]] = true;
        }
        bool flag = true;
        for(int i = 0;i<m;i++){
            if(check[i] == false){
                flag = false;
                break;
            }
        }

        if(flag)
            cout << n-count<< endl;
        else
            cout << -1 << endl;
        


    }
}
