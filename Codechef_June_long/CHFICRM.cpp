#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int chef5 = 0;
        int chef10 = 0;
        bool flag = 0;
        vector<int> arr(n);
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        for(int i = 0;i<n;i++){
            if(arr[i] == 5){
                chef5++;
                
            }
            else if(arr[i] == 10){
                if(chef5>0){
                    chef5--;
                    chef10++;
                }else{
                    cout << "NO" << "\n";
                    flag = 1;
                    break;
                }
            }
            else if(arr[i] == 15){
                if(chef10 > 0){
                    chef10--;
                    
                }else if(chef5 > 1){
                    chef5 = chef5-2;

                }else{
                    cout << "NO" << "\n";
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag)
             cout << "YES" << "\n";
    }
}
