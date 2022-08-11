#include<stack>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<deque>
#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<iomanip>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define endl "\n"
#define debug(a) cout<<#a<<"="<<a<<endl;
#define eps 1e-8
#define sqr(x) ((x)*(x))
using namespace std;
ll GCD(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
const int inf=0x3f3f3f3f;
const int N = 107;
ll p[N],x,ans,d[N],cnt,flag;
int n,m;
inline void insert(ll x)
{
    for (int i=62;i>=0;i--)
        if (x>>i)
            if (p[i])
                x^=p[i];
            else
            {
                p[i]=x;
                return;
            }
    flag=1;
}
inline void rebuild()
{
    for (int i=0;i<=62;i++)
        for (int j=i-1;j>=0;j--)
            if (p[i]&(1ll<<j))
                p[i]^=p[j];
    for (int i=0;i<=62;i++)
        if (p[i]) 
            d[cnt++]=p[i];
}
inline ll ask_kth(ll x)
{
    if (x>=(1ll<<cnt)) return -1;
    ll res=0;
    for (int i=0;i<=62;i++)
        if (x&(1ll<<i)) res^=d[i];
    return res;
}
inline void Case_Test()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        insert(x);
    }
    
    rebuild();
    cin>>m;
    while (m--)
    {
        cin>>x;
        if (flag&&x==1)
            cout<<0<<endl;
        else 
            if (!flag) cout<<ask_kth(x)<<endl;
            else cout<<ask_kth(x-1)<<endl;
        
    }
}

signed main() 
{
    #ifndef ONLINE_JUDGE
		    freopen("IO\\in.txt","r",stdin);
		    freopen("IO\\out.txt","w",stdout);
            clock_t start, end;
            start = clock();
    #endif
    IOS
    int _=1;
    //cin>>_;
    while (_--)
    {
        Case_Test();
    }

    #ifndef ONLINE_JUDGE
        end = clock();
        cout << endl << "Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    #endif
}