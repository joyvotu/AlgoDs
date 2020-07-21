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
bool dfs(vector<vector<int>> &mat,int si,int sj,int n){
    cout << si << " " << sj << endl;
    mat[si][sj] = 5;
    if(si-1 >= 0){
        if(mat[si-1][sj] == 2)
            return true;
        else if(mat[si-1][sj] == 3)
            dfs(mat,si-1,sj,n);
    }
    if(sj-1 >= 0){
        if(mat[si][sj-1] == 2)
            return true;
        else if(mat[si][sj-1] == 3)
            dfs(mat,si,sj-1,n);
    }
    if(si+1 < n){
        if(mat[si+1][sj] == 2)
            return true;
        else if(mat[si+1][sj] == 3)
            dfs(mat,si+1,sj,n);
    }
     if(sj+1 < n){
        if(mat[si][sj+1] == 2)
            return true;
        else if(mat[si][sj+1] == 3)
            dfs(mat,si,sj+1,n);
    }
    return false;
}
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<vector<int>> mat(n,vector<int>(n));
	    int si,sj;
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            cin >> mat[i][j];
	            if(mat[i][j] == 1){
	                si = i;
	                sj = j;
	            }
	        }
	    }
        printvii(mat);
	    if(dfs(mat,si,sj,n))
	        cout << 1 << endl;
	    else
	        cout << 0 << endl;
	    
	}
	return 0;
}



