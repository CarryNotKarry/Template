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
using namespace std;
ll GCD(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
const int inf=0x3f3f3f3f;
const int N = 507;
const ll mod = 1e9+7;
ll n,q,m,a[N][N],b[N][N],c[N][N];
inline void Case_Test()
{
    cin>>n>>q>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=q;j++)
            cin>>a[i][j];
    for (int i=1;i<=q;i++)
        for (int j=1;j<=m;j++)
            cin>>b[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=q;k++)
                c[i][j]=((a[i][k]*b[k][j])%mod+c[i][j]+mod)%mod;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
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