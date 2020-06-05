#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool colcomp(const vector<int> &v1,const vector<int> &v2){
    return v1[1]<v2[1];
}

int main() {
    vector< vector<int> > vect{{3, 5, 1},{4, 8, 6},{7, 2, 9}};

    sort(vect.begin(),vect.end(),colcomp);

    for(int i = 0;i<vect.size();i++){
        for(int j = 0;j<vect[0].size();j++){
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
