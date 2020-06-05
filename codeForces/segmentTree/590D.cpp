#include <bits/stdc++.h>
using namespace std;
string uniqueStr(string s1,string s2){
    unordered_set<char> s;
    string ans = "";
    for(char c : s1){
        if(s.find(c) == s.end()){
          s.insert(c);
          ans+= c;
        }
    } 
    for(char c: s2){
        if(s.find(c) == s.end()){
          s.insert(c);
          ans += c;
        }
    }
   
       
    return ans; 
}


void build(vector<string>& t,int tl,int tr,int v,string arr){
    if(tl == tr)
      t[v] = arr[tl];
    else{
        int mid = tl + (tr-tl)/2;
        build(t,tl,mid,2*v,arr);
        build(t,mid+1,tr,2*v+1,arr);
        t[v] = uniqueStr(t[2*v],t[2*v+1]);
    }
}

void update(vector<string> &t,int tl,int tr,int v,int pos,string newVal){
    if(tl == tr)
      t[v] = newVal;
    else{
        int mid = tl + (tr-tl)/2;
        if(pos <= mid)
          update(t,tl,mid,2*v,pos,newVal);
        else
          update(t,mid+1,tr,2*v+1,pos,newVal);
        t[v] = uniqueStr(t[2*v],t[2*v+1]);
    }
}
string getRange(vector<string> &t,int tl,int tr,int v,int l,int r){
    if(l > r)
      return "";
    if(tl == l && tr == r)
      return t[v];
    int mid = tl + (tr-tl)/2;
    return uniqueStr(getRange(t,tl,mid,2*v,l,min(mid,r)),getRange(t,mid+1,tr,2*v+1,max(l,mid+1),r));
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<string> t(4*n+1,"");
    build(t,0,n-1,1,s);
    int q;
    cin >> q;
    while(q--){
      string a,b,c;
      cin >> a >> b >> c;
      if(a == "1"){
          int pos = stoi(b);
          //cout << pos << endl;
         update(t,0,n-1,1,pos-1,c);
      }else{
          int l = stoi(b);
          int r = stoi(c);
         // cout << l << " " << r << endl;
          string ans = getRange(t,0,n-1,1,l-1,r-1);
          cout << ans.size() << endl;
      }
        
    }
    return 0;
}


