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




int main(){
    int seq[129];

    int lastoccur[100];
    int countofVisit[100];
    int t,n;

    for(int i = 0;i<129;i++){
        lastoccur[i] = 0;
        countofVisit[i] = 0;
    }
    cin>>t;
    seq[0] = 0;
        seq[1] = 0;
        lastoccur[0] = 0;
        countofVisit[0] = 2;


        for(int i = 2;i<129;i++){
            if(countofVisit[seq[i-1]] > 1){
                seq[i] = i-1 - lastoccur[seq[i-1]];
                countofVisit[seq[i]]++;
                lastoccur[seq[i-1]] = i-1;
            }else{
                seq[i] = 0;
                lastoccur[seq[i-1]] = i-1;
                countofVisit[0]++;
            }

        }


    while(t--){
        cin >> n;


        int count  = 0;
        for(int i = 0;i<n;i++){
            if(seq[i] == seq[n-1])
                count++;
        }

        cout << count << endl;

    }

    return 0;


}
