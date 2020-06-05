//
//  main.cpp
//  test02
//
//  Created by Joy Brahma on 08/02/20.
//  Copyright © 2020 Joy Brahma. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct team{

    int pts,wins,gscored,gagainst,games,goaldiff,loss,ties;
    char name[30];

    void init(){
       ties =  pts = wins = gscored = gagainst = games = goaldiff = loss = 0;
    }
    void record(int a,int b){
        games++;
        gscored += a;
        gagainst += b;
        if(a>b){
            wins++;
            pts += 3;
        }
        if(a == b){
             pts++;
            ties++;
        }


        if(b>a)
            loss++;

        goaldiff = gscored-gagainst;
    }

};

bool cmp(team a,team b){
    if(a.pts != b.pts)return a.pts>b.pts;
    if(a.wins != b.wins) return a.wins>b.wins;
    if(a.goaldiff != b.goaldiff) return a.goaldiff > b.goaldiff;
    if(a.gscored != b.gscored) return a.gscored > b.gscored;
    if(a.games != b.games) return a.games<b.games;
    return strcasecmp(a.name,b.name)<0;
}

int main(){
    int test;
    scanf("%d ", &test);


    while(test--){
        string tname;
        getline(cin,tname);
        //getchar();
         int n,m;
        scanf("%d ",&n);
         team t[50];
         unordered_map<string,int> map;

         for(int i = 0;i<n;i++){
             gets(t[i].name);

             t[i].init();
             map[t[i].name] = i;
         }
        scanf("%d ",&m);
         while(m--){
             char buf[100];
             char name1[30],name2[30];
             int a,b;
             gets(buf);
             //cin >> buf;
             sscanf(buf,"%[^#]#%d@%d#%[^\n]",name1,&a,&b,name2);
             t[map[name1]].record(a, b);
             t[map[name2]].record(b, a);

         }

        sort(t,t+n,cmp);
        cout << tname << endl;
         for(int i = 0;i<n;i++){
               printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                              i+1, t[i].name, t[i].pts, t[i].games,
                              t[i].wins, t[i].ties, t[i].loss, t[i].goaldiff,
                              t[i].gscored, t[i].gagainst);


         }
        map.clear();
        cout<< endl;


    }

    return 0;
}
