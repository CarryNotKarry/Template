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
const int N = 100010;
struct node
{
    int to,next,w;
}edge[N<<1];
int head[N],cnt,n,m,x,y,w,s,t,dis[N];
bool exist[N];
inline void add(int x,int to,int w)
{
    edge[++cnt].to=to;
    edge[cnt].next=head[x];
    edge[cnt].w=w;
    head[x]=cnt;
}
inline void Dij(int s,int t);
int main() 
{
    #ifndef ONLINE_JUDGE
		    freopen("IO\\in.txt","r",stdin);
		    freopen("IO\\out.txt","w",stdout);
        #endif
    IOS
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        add(x,y,w);add(y,x,w);
    }
    cin>>s>>t;
    Dij(s,t);
    return 0;
}
inline void Dij(int s,int t)
{
    memset(dis,0x7f/2,sizeof(dis));
    dis[s]=0;
    priority_queue<pair<int,int> > Q;
    Q.push({0,s});
    while (!Q.empty())
    {
        int x=Q.top().second;Q.pop();
        if (exist[x]) continue;
        if (x==t) break;
        exist[x]=true;
        for (int i=head[x];i;i=edge[i].next)
        {
            int y=edge[i].to,w=edge[i].w;
            if (dis[y]>dis[x]+w)
            {
                dis[y]=dis[x]+w;
                Q.push({-dis[y],y});
            }
        }
    }
    cout<<dis[t];
}