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
const ll mx = 1e9+7;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

bool check(int n, int i)
{
    return (n>>i)&1;
}

struct node
{
    node *zero, *one;
    node()
    {
        zero = one = NULL;
    }
}*root;

void insert(int n)
{
    node* curr = root;
    for(int i=31; i>=0; i--)
    {
        bool ok = check(n, i);
        if(ok)
        {
            if(curr->one==NULL)
                curr->one = new node();
            curr = curr->one;
        }
        else
        {
            if(curr->zero==NULL)
                curr->zero = new node();
            curr = curr->zero;
        }
    }
}

int get_max(int n)
{
    node* curr = root;
    int ret = 0;

    for(int i=31; i>=0; i--)
    {
        bool ok = check(n, i);
        if(ok)
        {
            if(curr->zero)
            {
                curr = curr->zero;
                ret|=(1<<i);
            }
            else
                curr = curr->one;
        }
        else
        {
            if(curr->one)
            {
                curr = curr->one;
                ret|=(1<<i);
            }
            else
                curr = curr->zero;
        }
    }
    return ret;
}

int get_min(int n)
{
    node* curr = root;
    int ret = 0;

    for(int i=31; i>=0; i--)
    {
        bool ok = check(n, i);
        if(ok)
        {
            if(curr->one)
                curr = curr->one;
            else
            {
                curr = curr->zero;
                ret|=(1<<i);
            }
        }
        else
        {
            if(curr->zero)
                curr = curr->zero;
            else
            {
                curr = curr->one;
                ret|=(1<<i);
            }
        }
    }
    return ret;
}

void del(node* cur)
{
    if(cur->one)
        del(cur->one);
    if(cur->zero)
        del(cur->zero);
    delete(cur);
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t, n, a;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        cin >> n;
        root = new node();
        insert(0);
        int mx = 0, mn = INT_MAX, now = 0;
        for(int i=1; i<=n; i++)
        {
            cin >> a;
            now^=a;
            mx = max(mx, get_max(now));
            mn = min(mn, get_min(now));

            insert(now);
        }

        cout << "Case " << i << ": " << mx << " " << mn << endl;
        del(root);
    }
    return 0;
}

