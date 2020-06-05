#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
   vector<int> v;
   
    int t,n;
    int arr[100005];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        int cursum = 0, maxsum = INT_MIN, start = 0,end = 0, tempstart = 0;
        for(int i = 0;i<n;i++){
            cursum += arr[i];
            if(cursum>maxsum){
                maxsum = cursum;
                end = i;
                start = tempstart;

            }else if(cursum < 0){
                tempstart = i+1;
                cursum = 0;
            }
        }
        cout << maxsum;
        cout << endl << start << " "<<end << endl;
    }
    return 0;
}
