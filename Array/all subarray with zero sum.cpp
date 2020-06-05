#include <bits/stdc++.h>
typedef long long ll;


using namespace std;
typedef vector<pair<int,int>> vii;


#define fr(i,n) for(int i = 0;i<n;i++)


int main(){
    int arr[100];
    int n;
    cin >> n;
    fr(i,n)
        cin >> arr[i];
    unordered_map <int,vector<int>> mp;
    int cumsum = 0;
    fr(i,n){
        cumsum += arr[i];
        if(cumsum == 0)
            cout << 0 << " " << i << endl;
        if(mp.find(cumsum) != mp.end()){

            vector<int> temp = mp[cumsum];
            for(auto it = temp.begin();it != temp.end(); it++)
                cout << *it + 1 <<  " " << i << endl;

        }

        mp[cumsum].push_back(i);
    }

}
