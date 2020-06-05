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

struct contestant{
    set<int> problemSolved;
    int addedtime[11];
    int cno,timePenalty;
    int psolved;
    void init(){
       cno = psolved = timePenalty = 0;
        problemSolved.clear();
        for(int i = 0;i<11;i++)
            addedtime[i] = 0;


    }
    void entry(int n,int pno,int time,char l){
        cno = n;
        //
        if(l == 'C'){

             timePenalty += time;
             problemSolved.insert(pno);

        }

        if(l == 'I'){
            if(problemSolved.count(pno) != 1 )
                addedtime[pno] += 20;
            else
                addedtime[pno] = 0;

        }

        if(problemSolved.count(pno)  == 1)
            timePenalty += addedtime[pno];
        psolved = int(problemSolved.size());
    }

};
contestant cs[101];
bool cmp(contestant a,contestant b){
    if(a.psolved != b.psolved)
        return a.psolved > b.psolved;
    else if(a.timePenalty != b.timePenalty)
        return b.timePenalty > a.timePenalty;
    return a.cno < b.cno;
}
void initc(){
    for(int i = 0;i<101;i++)
        cs[i].cno = 0;
}

int searchNo(int cno){
    for(int i = 0;i<101;i++){
        if(cs[i].cno == cno)
            return i;
    }

        return -1;
}

int main(){
    int t;
    scanf("%d\n", &t );
    //cin.ignore();
    //cin.ignore();



    while(t--){
        initc();
        int cno,pno,time;
        char op;
        int count = 0;
        char buff[101];
        int i = 0;
        while(gets(buff)  && buff[0] != '\0'){



            sscanf(buff,"%d %d %d %c", &cno , &pno , &time , &op);
            if(searchNo(cno) == -1){
                cs[i].init();
                cs[i].entry(cno, pno, time, op);
                count++;
            }else{
                int ind = searchNo(cno);
                cs[ind].entry(cno, pno, time, op);

            }



             i++;


        }
        sort(cs,cs+101,cmp);
        for(int i = 0;i<101;i++){
            if(cs[i].cno != 0)
            cout << cs[i].cno << " " << cs[i].psolved << " " << cs[i].timePenalty << endl;
        }

        cout << endl;






    }
    return 0;
}
