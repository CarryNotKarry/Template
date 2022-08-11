#include<stack>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<set>
#include<iomanip>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=3e5;
int len1,len2,ans,p[maxn];
char s[maxn],str[maxn];
void init()
{
    str[0]='!';
    str[1]='#';
    for (int i=0;i<len1;i++)
        str[i*2+2]=s[i],str[i*2+3]='#';
    len2=len1*2+2;
    str[len2]='*';
}
void manacher()
{
    int id=0,mx=0;
    for (int i=1;i<len2;i++)
    {
        if (mx>1) p[i]=min(p[2*id-1],mx-i);
        else p[i]=1;
        for (;str[i+p[i]]==str[i-p[i]];p[i]++);
        if (p[i]+i>mx)
            mx=p[i]+i,id=i;
    }
}
signed main() 
{
    #ifndef ONLINE_JUDGE
		    freopen("IO\\in.txt","r",stdin);
		    freopen("IO\\out.txt","w",stdout);
        #endif
    while (cin>>s)
    {
        len1=strlen(s);
        init();
        manacher();
        for (int i=0;i<len2;i++)
            ans=max(ans,p[i]);
        cout<<ans-1<<endl;
        /*
        output substring
        for (int i=pos-ans+1;i<=pos+ans-1;i++)
            if (str[i]!='#') cout<<str[i];
            */
        /*for (int i=0;i<=len2;i++) cout<<str[i]<<" ";
        cout<<endl;
        for (int i=0;i<=len2;i++) cout<<p[i]<<" ";
        cout<<endl;*/
    }
    return 0;
}