#include <bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>> 
#define vi vector<int>
#define ll Long Long
#define ld Long Double
#define vpi vector<pair<int,int>> 
#define mp make_pair
#define pb push_back
#define umap unordered_map<int,int> 

vii adj(10000);

void printvi(vector<int> a){
    for(int x: a){
        cout << x  << " ";
    }
    cout << endl;
}
void printvii(vii a){
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[i].size();j++){
            cout << a[i][j] << " " ;

        }
        cout << endl;
    }
}
void ipgraph(int m,int n){
    adj.clear();
    adj.resize(n+5);
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
       unordered_map<long,int> mpa,mpb;
        for(int i = 0;i<n;i++){
            long a;
            cin >> a;
            mpa[a]++;
        }

        for(int i = 0;i<n;i++){
            long b;
            cin >> b;
            mpb[b]++;
        }
        bool flag = true;
        for(auto i = mpa.begin();i!=mpa.end();i++){
            if(mpb.find(i->first) != mpb.end() && (mpa[i->first] + mpb[i->first]) & 1){
                flag = false;
                break;
            }else if(mpb.find(i->first) == mpb.end() && mpa[i->first] & 1){
                flag = false;
                break;
            }
                
        }

        if(flag){
            
        for(auto i = mpb.begin();i!=mpb.end();i++){
            if(mpa.find(i->first) != mpa.end() && (mpa[i->first] + mpb[i->first]) & 1){
                flag = false;
                break;
            }else if(mpa.find(i->first) == mpa.end() && mpb[i->first] & 1){
                flag = false;
                break;
            }
        }
        }
        if(!flag)
            cout << -1 << endl;
        else{
            for(auto it = mpa.begin();it!=mpa.end();it++){
                if(mpb.find(it->first) != mpb.end()){
                     if(mpb[it->first] > mpa[it->first]){
                        mpb[it->first] = mpb[it->first] - mpa[it->first];
                        mpa[it->first] = 0;
                    }else if(mpa[it->first] > mpb[it->first]){
                        mpa[it->first] = mpa[it->first] - mpb[it->first];
                        mpb[it->first] = 0;
                    }else if(it->second == mpb[it->first]){
                        int x = it->first;
                        mpa[x] = 0;
                        mpb[x] = 0;
                    }
                }
                     
            }
/*
            for(int i : rmb)
                mpb.erase(i);
            */
           vector<long> ans1,ans2;; 
            for(auto it = mpa.begin();it!= mpa.end();it++){
                if(it->second != 0){
                for(int i = 0;i<it->second/2;i++)
                    ans1.pb(it->first);
                }
            }

            for(auto it = mpb.begin();it!= mpb.end();it++){
                if(it->second != 0){
                for(int i = 0;i<it->second/2;i++)
                    ans2.pb(it->first);
                }

            }
            if(ans1.size() != ans2.size()){
                cout << -1 << endl;
                break;
            }
            sort(ans1.begin(),ans1.end());
            sort(ans2.begin(),ans2.end());
            long long cost1 = 0;
            long long cost2 = 0;
            for(int i = 0,j=ans2.size()-1;i<ans1.size();i++,j--){
                cost1 += min(ans1[i],ans2[j]);
            }
            for(int i = 0,j = ans1.size()-1;i<ans2.size();i++,j--){
                cost2 += min(ans1[j],ans2[i]);
            }
            cout << min(cost1,cost2) << endl;
        }




        
    }
    

    return 0;
}




