#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> a;
    bool check[3005];
    int k,x;
    while(scanf("%d", &k) != EOF){
        getchar();

        for(int i = 0;i<k;i++){
            cin >> x;
            a.push_back(x);

        }
        for(int i = 1;i<k;i++){
            check[i] = false;
        }
        for(int i = 0;i<k-1;i++){
            int diff;
            if(a[i]-a[i+1] > 0)
                diff = a[i]-a[i+1];
            else
                diff = a[i+1] - a[i];

            check[diff] = true;

        }
        bool flag = false;
        for(int i = 1;i<k;i++){
            if(check[i] == false){
                flag = true;
            }

        }
        if(flag ==  false)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
        a.clear();
    }

    return 0;

}
