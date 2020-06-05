#include <bits/stdc++.h>
using namespace std;
int fact(int n){
    int ans = 1;
    for(int i = 1;i<=n;i++)
      ans*= i;
    return ans;
}
int main(){
  for(int n = 1;n<=20;n++){
      int res = 0;
      cout << (n-1)*int(log(fact(n))) << " ";
      for(int i = 1;i<=n;i++){
          res += ((n-i+1)*int(log(i)));
      }
      cout << res << endl;
  }
  return 0;
}

