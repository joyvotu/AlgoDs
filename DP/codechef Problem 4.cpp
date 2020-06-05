//#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    scanf("%d", &t);

    while(t--){
        //cin >> n;
        scanf("%d",&n);
        vector<int> a;
        for(int i = 0;i<n;i++){
            int x;
            //cin >> x;
            scanf("%d",&x);
            a.push_back(x);
        }

        long count  = 0;
        bool oddflag  = 0;
        int divisor = 4;

        for(int i = 0;i<n;i++){
            if(a[i]%2!= 0)oddflag = 1;
            divisor = 4;
            for(int j = i;j<n;j++){
                if(divisor == 0){
                    count++;

                }

               else{
                   if(oddflag){
                       if(a[j]%2!=0)
                           count++;
                       else{
                           oddflag = 0;
                           if(a[j] == 0){
                               count  = count+n-j;
                               break;
                           }
                           else if(a[j]%divisor == 0){
                               count++;
                               divisor = 0;
                           }else{
                               divisor /= 2;
                           }
                       }

                   }else{

                       if(a[j] == 0){
                           count  = count+n-j;
                           break;
                       }
                       else if(a[j]%divisor == 0){
                           count++;
                           divisor = 0;
                       }else{
                           if(a[j]%2 == 0)
                               divisor /= 2;
                       }

                   }
               }
            }
        }
        printf("%ld\n" , count);
    }
}
