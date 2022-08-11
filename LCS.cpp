
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
const int N = 2007;
int f[N][N],n,l1,l2,steps[N][N];
string s1,s2;
inline void LCS(int x,int y);
int main() 
{
    #ifndef ONLINE_JUDGE
		    freopen("IO\\in.txt","r",stdin);
		    freopen("IO\\out.txt","w",stdout);
        #endif
    IOS
    cin>>s1>>s2;
    l1=s1.length();l2=s2.length();
    s1=" "+s1;s2=" "+s2;
    for (int i=1;i<=l1;i++)
    {
        for (int j=1;j<=l2;j++)
        {
            if (s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1,steps[i][j]=2;
            else
            {
                if (f[i-1][j]>f[i][j-1]) f[i][j]=f[i-1][j],steps[i][j]=3;
                else f[i][j]=f[i][j-1],steps[i][j]=1;
            }
        }
    }
    cout<<f[l1][l2]<<endl;
    LCS(l1,l2);
    return 0;
}
inline void LCS(int x,int y)
{
    if (steps[x][y]==2)
    {
        LCS(x-1,y-1);
        cout<<s2[y];
    }
    if (steps[x][y]==1) LCS(x,y-1);
    if (steps[x][y]==3) LCS(x-1,y);
}