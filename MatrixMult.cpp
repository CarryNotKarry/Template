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
#define int long long
using namespace std;
ll GCD(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
const int inf=0x3f3f3f3f;
const int mod = 1e9+7;
int n,p,m;
const int N = 5e2+7;
int a[N][N],b[N][N],res[N][N];
inline void Case_Test()
{
    cin>>n>>p>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=p;j++)
        {
            cin>>a[i][j];
            a[i][j]=(a[i][j]+mod)%mod;
        }
    for (int i=1;i<=p;i++)
        for (int j=1;j<=m;j++)
        {
            cin>>b[i][j];
            b[i][j]=(b[i][j]+mod)%mod;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=p;k++)
                res[i][j]=(res[i][j]+a[i][k]*b[k][j]+mod*100)%mod;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            cout<<res[i][j]<<" ";
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