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
ll arr[mx];

struct Tree{
   ll sum, prop;
}tree[4*mx];

void build(ll node, ll start, ll end)
{
    if(start==end){
            tree[node].sum = arr[start];
            return;
    }
    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (start+end)>>1;

    build(left, start, mid);
    build(right, mid+1, end);

    tree[node].sum = tree[left].sum+tree[right].sum;
}

void update(ll node, ll start, ll end, ll i, ll j, ll value)
{
    if(j<start || i>end)
             return;
    if(start>=i && end<=j){
             tree[node].sum += ((end-start+1)*value);
             tree[node].prop += value;
             return;
    }
    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (start+end)>>1;

    update(left, start, mid, i, j, value);
    update(right, mid+1, end, i, j, value);

    tree[node].sum = tree[left].sum+tree[right].sum+((end-start+1)*tree[node].prop);
}

ll query(ll node, ll start, ll end, ll i, ll j, ll carry=0)
{
    if(i>end || j<start)
            return 0;
    if(start>=i && end<=j)
            return tree[node].sum+carry*(end-start+1);

    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (start+end)>>1;

    ll x = query(left, start, mid, i, j, carry+tree[node].prop);
    ll y = query(right, mid+1, end, i, j, carry+tree[node].prop);

    return (x+y);
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, q, m, cs=0, type;
    scanf("%lld", &t);

    while(t--){
             scanf("%lld %lld", &n, &q);
             for(int i=1; i<=n; i++){
                        arr[i] = 0;
             }
             build(1, 1, n);
             printf("Case %lld:\n", ++cs);
             while(q--){
                        ll l, r, value, pos;
                        scanf("%lld", &type);
                        if(type==0){
                                scanf("%lld %lld %lld", &l, &r, &value);
                                l++, r++;
                                update(1, 1, n, l, r, value);
                        }
                        else{
                                scanf("%lld %lld", &l, &r);
                                l++, r++;
                                printf("%lld\n", query(1, 1, n, l, r));
                        }
             }
             for(int i=1; i<=3*n; i++){
                        tree[i].sum = tree[i].prop = 0;
             }
    }
    return 0;
}


