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
int tree[3*mx], arr[mx];

void build(int node, int start, int end)
{
    if(start==end){
            tree[node] = arr[start];
            return;
    }

    int left = 2*node;
    int right = 2*node+1;
    int mid = (start+end)>>1;

    build(left, start, mid);
    build(right, mid+1, end);

    tree[node] = min(tree[left],tree[right]);
}

ll query(int node, int start, int end, int i, int j)
{
    if(i>end || j<start)
            return INT_MAX;
    if(start>=i && end<=j)
            return tree[node];

    int left = 2*node;
    int right = 2*node+1;
    int mid = (start+end)>>1;

    int x = query(left, start, mid, i, j);
    int y = query(right, mid+1, end, i, j);

    return min(x,y);
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, n, k, m, a, b, c, d, l, r, cs=1;
    scanf("%d", &t);

    while(t--){
             scanf("%d %d", &n, &k);
             for(int i=1; i<=n; i++){
                        scanf("%d", &arr[i]);
             }
             printf("Case %d:\n", cs++);
             build(1, 1, n);
             while(k--){
                        scanf("%d %d", &l, &r);
                        printf("%lld\n", query(1, 1, n, l, r));
             }
    }
    return 0;
}

