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
ll p[N],x,ans;
int n;
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
}
inline void Case_Test()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        insert(x);
    }
    for (int i=62;i>=0;i--)
        if ((ans^p[i])>ans) ans=ans^p[i];
    cout<<ans;
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