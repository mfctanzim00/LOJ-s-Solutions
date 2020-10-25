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

struct Info
{
   ll mn, mx;
}tree[3*mx];
ll arr[mx], cs;

void build(ll node, ll start, ll end)
{
    if(start==end){
            tree[node].mn = arr[start];
            tree[node].mx = arr[start];
            return;
    }

    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (start+end)>>1;

    build(left, start, mid);
    build(right, mid+1, end);

    tree[node].mn = min(tree[left].mn, tree[right].mn);
    tree[node].mx = max(tree[left].mx, tree[right].mx);
}

Info combine(Info a, Info b)
{
    Info ans;
    ans.mx = max(a.mx, b.mx);
    ans.mn = min(a.mn, b.mn);
    return ans;
}

 Info query(ll node, ll start, ll end, ll i, ll j)
{
    if(i>end || j<start)
            return {INT_MAX, 0};
    if(start>=i && end<=j)
            return tree[node];

    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (start+end)>>1;

    Info x = query(left, start, mid, i, j);
    Info y = query(right, mid+1, end, i, j);

    return combine(x, y);
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, d;
    cin >> t;

    while(t--){
             cin >> n >> d;
             for(int i=1; i<=n; i++){
                        cin >> arr[i];
             }
             build(1, 1, n);
             ll ans = 0;
             for(int i=1; i-d+1<=n; i++){
                        Info ret = query(1, 1, n, i-d+1, i);
                        ll maxx = 0, minn = INT_MAX;
                        //cout << ret.mx << " " << ret.mn << " : " << i << " " << i-d+1 << endl;
                        maxx = max(maxx, ret.mx);
                        minn = min(minn, ret.mn);
                        ans = max(ans, maxx-minn);
                        //cout << maxx << " " << minn << endl;
             }

             cout << "Case " << ++cs << ": " << ans << endl;

             for(int i=1; i<=3*n; i++){
                        tree[i].mx = 0;
                        tree[i].mn = INT_MAX;
             }
    }
    return 0;
}
