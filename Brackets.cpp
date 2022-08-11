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
string s;
const int N = 207;
int dp[N][N];
inline void Case_Test()
{
    while (cin>>s)
    {
        if (s=="end") return;
        memset(dp,0,sizeof(dp));
        int len=s.size();
        for (int k=1;k<len;k++)
        {
            for (int i=0,j=k;j<len;i++,j++)
            {
                if ((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
                    dp[i][j]=dp[i+1][j-1]+2;
                for (int d=i;d<j;d++)
                    dp[i][j]=max(dp[i][j],dp[i][d]+dp[d+1][j]);
            }
        }
        cout<<dp[0][len-1]<<endl;
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