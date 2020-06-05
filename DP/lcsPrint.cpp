#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vii;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define For(a,b,c) for(a=b;a<c;a++)
#define ForD(a,b,c) for(a=b-1;a>=c;a--)
vector<string> getAll(int dp[][100],string str1,string str2,int len1,int len2){
    if(len1==0 or len2==0){
        vector<string> v(1);
        return v;
    }
    if(str1[len1-1]==str2[len2-1]){
        vector<string> lcs=getAll(dp,str1,str2,len1-1,len2-1);
        for(string &s:lcs){
            s.push_back(str1[len1-1]);
        }
        return lcs;
    }
    if(dp[len1-1][len2]>dp[len1][len2-1]){
        return getAll(dp,str1,str2,len1-1,len2);
    }
    if(dp[len1-1][len2]<dp[len1][len2-1]){
        return getAll(dp,str1,str2,len1,len2-1);
    }
    vector <string> top= getAll(dp,str1,str2,len1-1,len2);
    vector <string> left= getAll(dp,str1,str2,len1,len2-1);
    top.insert(top.end(),left.begin(),left.end());
    return top;
}
set<string> getFills(int dp[][100],string str1,string str2,int len1,int len2){
    vector<string> vec=getAll(dp,str1,str2,len1,len2);
    set<string> str(vec.begin(),vec.end());
    return str;
}
void fillDP(int dp[][100],string str1,string str2,int len1,int len2){
    int i,j;
    For(i,1,len1+1){
        For(j,1,len2+1){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int len1,len2;
        cin>>len1>>len2;
        string str1,str2;
        cin>>str1>>str2;
        int dp[100][100]={0};
        fillDP(dp,str1,str2,len1,len2);
        cout<<"Length: "<<dp[len1][len2]<<endl;
        set<string> st=getFills(dp,str1,str2,len1,len2);
        for(set<string>::iterator it=st.begin();it!=st.end();it++){
            cout<<*it<<endl;
        }
    }
    return 0;
}
