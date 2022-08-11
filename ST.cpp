#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
inline int Min(int x,int y) {if (x>y) return y;return x;}
int l,r,w,lg2[200010],f[200010][20],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&f[i][0]);
	for (int i=2;i<=n;i++)
		lg2[i]=lg2[i>>1]+1;
	for (int i=n;i>=1;i--)
		for (int j=1;i+(1<<j)-1<=n;j++)
			f[i][j]=Min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		w=lg2[r-l+1];
		printf("%d\n",Min(f[l][w],f[r-(1<<w)+1][w]));
	}
}
/*
int lg2[N],f[N][20];
inline void init()
{
	for (int i=2;i<=n;i++)
		lg2[i]=lg2[i>>1]+1;
	for (int i=n;i>=1;i--)
		for (int j=1;i+(1<<j)-1<=n;j++)
			f[i][j]=Min(f[i][j-1],f[i+(1<<j-1)][j-1]);
}
inline int calc(int l,int r)
{
	int w = lg2[r-l+1];
	return Min(f[l][w],f[r-(1<<w)+1][w]);
}
}*/