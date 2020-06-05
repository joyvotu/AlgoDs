#include <bits/stdc++.h>

using namespace std;

char arr[15][25];
int maxb(int n){
    int res = 999;
    int maxb= 0;
    for(int i = 0;i<n;i++){
        maxb = 0;
        for(int j = 0;j<25;j++){
           if(arr[i][j] == ' ')
               maxb++;
        }
        if(res > maxb )
            res = maxb;
    }
    return res;
}

int solver(int mb,int n){
    int res = 0;
    int countb = 0;
    for(int i = 0;i<n;i++){
        countb = 0;
        for(int j = 0;j<25;j++){
            if(arr[i][j] == ' ')
                countb++;
        }
        res += countb-mb;
    }
    return res;
}
int main(){
    int n;
    while(1){

        cin >> n;
        getchar();
        if(n == 0)
            break;

        //cout << 34;

        for(int i = 0;i<n;i++){
            string s;
            getline(cin, s);
            for(int j = 0;j<25;j++){
                arr[i][j] = s[j];
            }
        }
        int mb = maxb(n);
        cout << solver(mb,n) << endl;

    }

    return 0;

}
