#include <bits/stdc++.h>
using namespace std;
int modu = 1e9+7;
int factors(int n){
    int res = 0;
    for(int i = 1;i*i<=n;i++){
        if(n % i == 0){
            if(n/i == i)
                res++;
            else
                res = res +2;
        }

    }
    return res;
}
vector<int> g[100002];
int parent[100002];
bool visited[100002];
//int table[100002][100002];
void init(int n){
    for(int i = 0;i<=n;i++){
        g[i].clear();

        for(int j = 0;j<=n;j++){
           // table[i][j] = -1;

        }
    }
}

bool dfs(int x,int y){
    stack<int> s;
    s.push(x);
    while(!s.empty()){
        int v= s.top();
        s.pop();
        if(visited[v])
            continue;
        visited[v] = true;
        for(auto it = g[v].begin();it!=g[v].end();it++){
            if(!visited[*it]){
                parent[*it] = v;
                if(*it == y)
                    return true;
                s.push(*it);
            }
        }
    }
    return false;
}
void dfsutil(int x,int y,int n){
    for(int i = 1;i<=n;i++){
        visited[i] = false;
        parent[i] = -1;
    }
    bool f = dfs(x,y);
}

int main(){
    int t,n;
    scanf("%d" ,&t);
    while(t--){
        scanf("%d", &n);
        init(n);
        int cost[n+1];
        for(int i = 0;i<n-1;i++){
            int x,y;
            scanf("%d %d",&x ,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i = 0;i<n;i++){
            scanf("%d" ,&cost[i+1]);
            //table[i+1][i+1] = factors(cost[i+1]);
        }
        int q;
        scanf("%d", &q);
        while(q--){
            int x,y;
            cin >> x >> y;
            if(x == y)
                printf("%d\n",factors(cost[x]));
            else{
            dfsutil(x,y,n);
            int i = y;
            int c = cost[y]%modu;
            while(i!=x){

                c = (c * cost[parent[i]])%modu;
                i = parent[i];
            }
                //table[x][y] = factors(c);
                printf("%d\n",factors(c));

            }
        }
    }

}
