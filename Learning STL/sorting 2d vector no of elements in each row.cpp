#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sizecomp(const vector<int>& v1,const vector<int>& v2){
    return v1.size()<v2.size();
}

int main(){
    vector<vector<int>> v{{1, 2},
                         {3, 4, 5},
                                 {6}};
    sort(v.begin(),v.end(),sizecomp);

    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }

        cout << endl;
    }
    return 0;

}
