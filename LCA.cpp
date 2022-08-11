const int N = 3e5+7;
struct Edge
{
	int to,next;
}edge[N*2+7];
int cnt,head[N],dep[N],f[N][21],Q,n,x,y,lg2[N],root;
inline void add(int x,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void Build(int x,int pre)
{
	dep[x]=dep[pre]+1;
	f[x][0]=pre;
	for (int i=1;i<=20;i++)
		f[x][i]=f[ f[x][i-1] ][i-1];
	for (int i=head[x];i;i=edge[i].next)
		if (edge[i].to!=pre)
			Build(edge[i].to,x);
}
int Lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
    while (dep[x]>dep[y])
    	x=f[x][lg2[dep[x]-dep[y]]];
	if (x==y) return x;
	for (int i=lg2[dep[x]];i>=0;i--)
		if (f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}