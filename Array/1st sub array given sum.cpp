#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//1 2 3 4 5 7  --
int main(){
    int t,n,sum;
    int arr[100005];
    cin >> t;
    while(t--){

        cin >> n >> sum;
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }

        int cursum = 0, start = 0 , end = 0 , index = 0;

        //bool flag = false;

        for(int  i = 0;i<=n;i++){

            if(i == n){
                cout << -1 << endl;
                break;
            }
            cursum += arr[i];

            while(cursum > sum && start < i ){
                cursum -= arr[start++];
            }

             if(cursum == sum){
                cout << start+1 << " " << i+1 <<endl;
                break;
            }


        }
    }
    return 0;
}
