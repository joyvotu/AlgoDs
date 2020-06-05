#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define scan(t) scanf("%d", &t)
#define scanl(t) scanf("%lld", &t)
#define print(t) printf("%d\n" ,t)
#define printl(t) printf("%lld\n" ,t)
#define vi  vector<int>
#define vii vector<vector<int>>
#define vp  vector<pair<int,int>>
#define umap unordered_map<int,int>
#define fr(i,n)  for(int i = 0;i<n;i++)
#define frr(i,n)  for(int i = n-1;i>=0;i--)

struct node{
    int data;
    node* left;
    node* right;
};
node* newNode(int val){
    node* temp = new node;
    temp -> data = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
node* buildTree(vector<string>& ip){

    queue<node*> q;
    if(ip.size() == 0 || ip[0] == "N")
        return NULL;
    node* root = newNode(stoi(ip[0]));
    q.push(root);
    int i = 1;
    while(!q.empty() && i < ip.size()){
        node* cur = q.front();
        q.pop();
        if(ip[i] != "N"){
            cur -> left = newNode(stoi(ip[i]));
            q.push(cur->left);
           
        }
        i++;
        if(i >= ip.size())
            break;
        if(ip[i] != "N"){
                   cur -> right = newNode(stoi(ip[i]));
                   q.push(cur->right);
                   
        }
        i++;
    }
    return root;
}
void preorder(node* n){
    if(n != NULL){
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }
}
int main(){
    int t;
    cin >> t;
    vector<string> s;
    while(t--){

        string temp;
        cin >> temp;
        s.push_back(temp);
    }
    node* root = buildTree(s);
    preorder(root);


}
