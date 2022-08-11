#include<stack>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<iostream>
#include<map>
#include<set>
#include<iomanip>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int inf=0x3f3f3f3f;
const int N = 1007;
int l1,l2,ans,f[N][N],len,maxn,s;
string st;
int main() 
{
    #ifndef ONLINE_JUDGE
		    freopen("IO\\in.txt","r",stdin);
		    freopen("IO\\out.txt","w",stdout);
        #endif
    IOS
    cin>>st;
    len=st.length();
    if (len==0||len==1) {cout<<st;return 0;}
    maxn=1;
    for (int i=0;i<len;i++)
    {
        f[i][i]=1;
        if (i+1<len&&st[i]==st[i+1]) f[i][i]=2,maxn=2,s=i;
    }
    for (int l=3;l<=len;l++)
    {
        for (int i=0;i+l-1<len;i++)
        {
            int j=i+l-1;
            if (st[i]==st[j]&&f[i+1][j-1]==1)
                f[i][j]=1,s=i,maxn=l;
        }
    }
    cout<<st.substr(s,maxn);
    return 0;
}