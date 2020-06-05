//
//  main.cpp
//  TESTER
//
//  Created by Joy Brahma on 18/10/19.
//  Copyright © 2019 Joy Brahma. All rights reserved.
//

#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll ugly[10003];


ll min(ll a, ll b, ll c)
{
    if (a < b)
    {
        if (a < c)
            return a;
        else
            return c;
    }
    else if (b < c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

ll solver(int n){
    ugly[0] = 1;
    ll i,j,k;
    i = j = k = 0;
    for(int x = 1;x<n;x++){


    ll mul_2 = ugly[i]*2;
    ll mul_3 = ugly[j]*3;
    ll mul_5 = ugly[k]*5;

    ll nextugly = min(mul_2,mul_3,mul_5);
    if(nextugly == mul_2)
        i++;
    if(nextugly == mul_3)
        j++;
    if(nextugly == mul_5)
        k++;
    ugly[x] = nextugly;

    }

    return ugly[n-1];


}

int main()
{
    ll t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        ll t = solver(n);
        cout << t << endl;
    }
    return 0;
}
