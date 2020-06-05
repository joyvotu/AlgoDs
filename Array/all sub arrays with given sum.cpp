#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void printsubarrayindices(int arr[],int n,int sum){
    int cursum = 0;
    unordered_map<int, vector<int>> map;
    map[0].push_back(-1);
    for(int i = 0;i<n;i++){
        cursum += arr[i];
        if(map.find(cursum-sum) != map.end()){
            int size = int(map[cursum-sum].size());
            for(auto it = map[cursum-sum].begin();it != map[cursum-sum].end();it++){
                cout << (*it)+1 <<  " " << i << endl;
            }

        }

        map[cursum].push_back(i);
    }
}
int main(){

    int arr[] = {3,4,-7,1,3,3,1,-4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printsubarrayindices(arr, n, 7);

}
