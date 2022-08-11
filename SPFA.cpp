#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N = 100010;
struct Edge{int to,next,w;}edge[1000010];
int head[N],cnt,u,v,n,m,dis[N],w;
bool exist[N];
inline void add(int x,int to,int w);
inline void SPFA();
queue<int> Q;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	SPFA();
}
inline void add(int x,int to,int w)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[x];
	edge[cnt].w=w;
	head[x]=cnt;
}
inline void SPFA()
{
	memset(dis,0x7f/2,sizeof(dis));
	dis[1]=0;
	Q.push(1);exist[1]=true;
	while (!Q.empty())
	{
		int u=Q.front();Q.pop();exist[u]=false;
		for (int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to,w=edge[i].w;
			if (dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if (!exist[v]) {Q.push(v);exist[v]=true;}
			}
		}
	}
	printf("%d",dis[n]);
}