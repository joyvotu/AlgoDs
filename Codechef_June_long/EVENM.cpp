#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n,vector<int>(n));
        int counter = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                arr[i][j] = counter++; 
            }
        }
        counter = 0;
        if(n%2 == 0){
            for(int i = 0;i<n;i++){
                if(counter%2 != 0)
                    reverse(arr[i].begin(),arr[i].end());
                counter++;
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
