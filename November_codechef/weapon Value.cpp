//
//  main.cpp
//  November Challange
//
//  Created by Joy Brahma on 02/11/19.
//  Copyright © 2019 Joy Brahma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
 int a[100005][10];

int main() {

    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    string s;
    int res[10];


    for(int i = 0;i<n;i++){
        cin >> s;
        for(int j = 0;j<10;j++){

           a[i][j] = s[j]-'0';

        }
    }


   for(int i = 0;i<10;i++)
        res[i] = 0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<10;j++){
            res[j] = res[j]^a[i][j];
        }
    }
   int count = 0;
    for(int i = 0;i<10;i++){
        if(res[i]==1)
            count++;
    }
    cout << count << endl;

    }

    return 0;


}
