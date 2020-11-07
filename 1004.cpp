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
const ll mod = 1e9+7;
const ll mx = 2e6+10;

int posx[] = {1,-1, 0, 0};
int posy[] = {0, 0, 1,-1};
ll n, arr[300][300], dp[300][300], cs;

ll Dfs(ll i, ll j)
{
    if(i>2*n-1 || j<1 || j>n)return 0;

    if(~dp[i][j]) return dp[i][j];

    ll ret;
    if(i<n){
           ret = arr[i][j]+max(Dfs(i+1, j+1), Dfs(i+1, j));
    }
    else ret = arr[i][j]+max(Dfs(i+1, j-1), Dfs(i+1, j));

    return dp[i][j] = ret;
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1;
    cin >> t;

    while(t--){
            cin >> n;
            memset(dp, -1, sizeof(dp));
            memset(arr, 0, sizeof(arr));
            for(ll i=1; i<=n; i++){
                     for(ll j=1; j<=i; j++){
                              cin >> arr[i][j];
                     }
            }
            for(ll i=1; i<n; i++){
                     for(ll j=1; j<=n-i; j++){
                              cin >> arr[i+n][j];
                     }
            }
            cout << "Case " << ++cs << ": " << Dfs(1, 1) << '\n';

    }
    return 0;
}
