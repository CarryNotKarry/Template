#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
char sa[1000010],sb[1000010];
int lena,lenb,j,nxt[1000010];
int main()
{
  scanf("%s",sa+1);lena=strlen(sa+1);
  scanf("%s",sb+1);lenb=strlen(sb+1);
  for (int i=2;i<=lenb;i++)
    {
      j=nxt[i-1];
      while (j>0&&sb[j+1]!=sb[i]) j=nxt[j];
      if (sb[j+1]==sb[i]) nxt[i]=j+1;
    }
  j=0;
  for (int i=1;i<=lena;i++)
    {
      while (j>0&&sa[i]!=sb[j+1]) j=nxt[j];
      if (sa[i]==sb[j+1]) j++;
      if (j==lenb) printf("%d\n",i-lenb+1);
    }
  for (int i=1;i<=lenb;i++)
      printf("%d ",nxt[i]);
  return 0;
}