//
//  dp.cpp
//  noOfways
//
//  Created by Joy Brahma on 17/10/19.
//  Copyright © 2019 Joy Brahma. All rights reserved.
//

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int rec(int start,int end,int m,int n,int c){
    if(start <= m && end <= n ){
        if(start == m && end == n){
            c+= 1;
            return c;
        }
                
                
            
            else{
                return rec(start+1,end,m,n,c)+rec(start,end+1,m,n,c);
            }
    }
    return 0;
}

int main(){
    cout << "hi";
}
