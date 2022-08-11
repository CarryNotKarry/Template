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
const int N = 100010;
struct Edge {int to,next;}edge[N];
int dfn[N],low[N],scc,top,sta[N],dfs_num,n,m,x,y,cnt,head[N];
bool exist[N];
inline void add(int x,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=++dfs_num;
	exist[x]=true;sta[++top]=x;
	for (int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if (!dfn[y])
		{
			Tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (exist[y]) low[x]=min(low[x],dfn[y]);
	}
	if (dfn[x]==low[x])
	{
		int now=0;scc++;
		while (x!=now)
		{
			now=sta[top--];
			exist[now]=0;
		}
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
		    freopen("IO\\in.txt","r",stdin);
		    freopen("IO\\out.txt","w",stdout);
        #endif
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]) Tarjan(i);
	printf("%d",scc);
	return 0;
}