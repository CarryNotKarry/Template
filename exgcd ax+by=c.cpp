#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp-(a/b)*y;
    return r;
}
int main()
{
    int a,b,c,x,y,gcd,t;
    scanf("%d%d%d",&a,&b,&c);
    gcd=exgcd(a,b,x,y);
    t=c/gcd;
    int x1=x*t,y1=y*t;
    printf("%d %d\n",x1,y1);
    return 0;
}
