#include<bits/stdc++.h>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl

struct Trie{
    struct node{
        node *nxt[2];
        node(){
            nxt[0] = nxt[1] = NULL;
        }
    }*root;

    Trie(){
        root = new node();
    }

    void Insert(int n){
        node *cur = root;
        for(int i=30; i>=0; i--){
            bool f = (bool)((1<<i)&n);
            if(cur->nxt[f] == NULL){
                cur->nxt[f] = new node();
            }
            cur = cur->nxt[f];
        }
    }

    int getMx(int n){
        int curAns=0;
        node *cur = root;
        for(int i=30; i>=0; i--){
            bool f = (bool)((1<<i)&n);
            if(cur->nxt[!f] != NULL){
                curAns |= (1<<i);
                cur = cur->nxt[!f];
            }
            else if(cur->nxt[f] != NULL){
                cur = cur->nxt[f];
            }
            else break;
        }
        return curAns;
    }

    int getMn(int n){
        int curAns=0;
        node *cur = root;
        for(int i=30; i>=0; i--){
            bool f = (bool)((1<<i)&n);
            if(cur->nxt[f] != NULL){
                cur = cur->nxt[f];
            }
            else if(cur->nxt[!f] != NULL){
                curAns |= (1<<i);
                cur = cur->nxt[!f];
            }
            else break;
        }
        return curAns;
    }

    void del(node* cur){
        if(cur->nxt[1])
            del(cur->nxt[1]);
        if(cur->nxt[0])
            del(cur->nxt[0]);
        delete(cur);
    }
};

int main()
{
    int t=1, n, m, k, cs=0;
    scanf("%d", &t);

    while(t--){
            scanf("%d", &n);

            Trie tree;
            tree.Insert(0);

            int prfXOR = 0, mx=INT_MIN, mn=INT_MAX;
            for(int i=1; i<=n; i++){
                    scanf("%d", &k);
                    prfXOR ^= k;
                    mx = max(mx, tree.getMx(prfXOR));
                    mn = min(mn, tree.getMn(prfXOR));
                    tree.Insert(prfXOR);
            }
            printf("Case %d: %d %d\n", ++cs, mx, mn);
            tree.del(tree.root);
    }
    return 0;
}
