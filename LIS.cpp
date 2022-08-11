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
const int N=1007;
int a[N],d[N],len,n,pos[N],ans[N];
int main() 
{
    #ifndef ONLINE_JUDGE
		    freopen("IO\\in.txt","r",stdin);
		    freopen("IO\\out.txt","w",stdout);
        #endif
    IOS;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    d[1]=a[1];len=1;pos[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]>d[len]) d[++len]=a[i],pos[i]=len;
        else
        {
            int t=upper_bound(d+1,d+1+len,a[i])-d;
            //d单调递增
            //最长上升子序列  不下降用lower_bound
            d[t]=a[i];
            pos[i]=t;
        }
    }
    cout<<len<<endl;
    int tmp=len,cnt=n;
    while (tmp)
    {
        while (cnt!=tmp) cnt--;
        ans[tmp]=cnt;
        tmp--;
    }
    return 0;
}