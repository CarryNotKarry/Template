#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#define N 100000000
using namespace std;
bool isprime[N];
int prime[N],num_prime=0,n,q,k;
int main()
{
	scanf("%d%d",&n,&q);
	memset(isprime,1,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for (int i=2;i<=n+1;i++)
	{
		if (isprime[i]) prime[++num_prime]=i;
		for (int j=1;j<=num_prime&&i*prime[j]<n+1;j++)
		{
			isprime[i*prime[j]]=false;
			if (!(i%prime[j])) break;
		}
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&k);
		if (isprime[k]) printf("Yes\n");
		else printf("No\n");
	}
}