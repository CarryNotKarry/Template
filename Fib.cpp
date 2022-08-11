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
int n,mod;
struct Matrix
{
    int a[3][3];
    Matrix(){memset(a,0,sizeof(a));}
    Matrix operator*(const Matrix &b) const
    {
        Matrix res;
        for (int i=1;i<=2;i++)
            for (int j=1;j<=2;j++)
                for (int k=1;k<=2;k++)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%mod;
        return res;
    }
}ans,base;
inline void init()
{
    base.a[1][1]=base.a[1][2]=base.a[2][1]=1;
    ans.a[1][1]=ans.a[1][2]=1;
}
inline void ksm(int b)
{
    while (b)
    {
        if (b&1) ans=ans*base;
        base=base*base;
        b>>=1;
    }
}
inline void Case_Test()
{
    cin>>n>>mod;
    if (n==1||n==2) {cout<<1;return;}
    init();
    ksm(n-2);
    cout<<ans.a[1][1];
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