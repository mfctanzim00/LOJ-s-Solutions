#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl

int ans;

int getVal(char c)
{
    if(c=='A')return 0;
    else if(c=='C')return 1;
    else if(c=='G')return 2;
    else return 3;
}

struct Trie{
    struct node{
        node *nxt[4];
        int cnt;
        node(){
            cnt=0;
            for(int i=0; i<4; i++){
                nxt[i] = NULL;
            }
        }
    }*root;

    Trie(){
        root = new node();
    }

    void Insert(char ch[], int n){
        node *cur = root;
        for(int i=0; i<n; i++){
            int x = getVal(ch[i]);
            if(cur->nxt[x] == NULL){
                cur->nxt[x] = new node();
            }
            cur = cur->nxt[x];
            cur->cnt++;
        }
    }

    void solve(node *root, int curLen){
        ans = max(ans, curLen * root->cnt);
        for(int i=0; i<4; i++){
            if(root->nxt[i] != NULL){
                solve(root->nxt[i], curLen+1);
            }
        }
    }
};

int main()
{
    int t=1, n, m, k, cs=0;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        Trie tree;
        getchar();
        for(int i=1; i<=n; i++){
            char ch[51];
            gets(ch);
            tree.Insert(ch, strlen(ch));
        }
        ans=1;
        tree.solve(tree.root, 0);

        printf("Case %d: %d\n", ++cs, ans);
    }
    return 0;
}
