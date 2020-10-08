#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;
const int mx = 2e5+9;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
int tree[100006];
char s[100006];

void BIT_update(int idx, int n, int value)
{
    while(idx<=n){
             tree[idx]+=value;
             idx+=(idx&(-idx));
    }
}

ll query(int idx)
{
    ll sum = 0;
    while(idx){
             sum+=tree[idx];
             idx-=(idx&(-idx));
    }
    return sum;
}

void range_up(int l, int r, int n)
{
    BIT_update(l, n, 1);
    BIT_update(r+1, n, -1);
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, n, k, m, a, b, c, d, q, cs = 1, pos, l, r;
    scanf("%d", &t);

    while(t--){
             memset(tree, 0, sizeof(tree));
             scanf("%s", s);
             n = strlen(s);

             scanf("%d", &q);
             printf("Case %d:\n", cs++);
             while(q--){
                        getchar();
                        char ch;
                        scanf("%c", &ch);

                        if(ch=='I'){
                                  scanf("%d %d", &l, &r);
                                  range_up(l, r, n);
                        }
                        else{
                                  scanf("%d", &pos);
                                  int ret = query(pos);
                                  int value = s[pos-1]-'0';
                                  if(ret&1){
                                           printf("%d\n", (value?0: 1));
                                  }
                                  else{
                                           printf("%d\n", value);
                                  }
                        }
             }
    }
    return 0;
}

