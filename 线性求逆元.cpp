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
#define debug(a) cout<<#a<<"="<<a<<endl;
#define eps 1e-8
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int MAXN = 3e6+7;
int n,p,inv[MAXN];
inline void Case_Test()
{
    cin>>n>>p;
    int mod=p;
    inv[1]=1;
    for (int i = 2; i < MAXN; i++)
	    //inv[i] = mul(inv[mod%i], mod - mod / i, mod);
        inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
    for (int i=1;i<=n;i++) cout<<inv[i]<<endl;
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