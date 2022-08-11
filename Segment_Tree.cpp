#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define int long long
using namespace std;
const int N = 100010;
int a[N];
struct Segment_Tree
{
    int sumv[N<<2],addv[N<<2],lc[N<<2],rc[N<<2];
#define lson (o<<1)
#define rson (o<<1|1)
#define mid ((l+r)>>1)
    inline void build(int o,int l,int r)
    {
        lc[o]=l;rc[o]=r;addv[o]=0;
        if (l==r) {sumv[o]=a[l];return ;}
        build(lson,l,mid);build(rson,mid+1,r);
        pushup(o);
    }
    inline void pushup(int o)
    {
        sumv[o]=sumv[lson]+sumv[rson];
    }
    inline void pushdown(int o)
    {
        if (addv[o])
        {
            sumv[lson]+=addv[o]*(rc[lson]-lc[lson]+1);
            sumv[rson]+=addv[o]*(rc[rson]-lc[rson]+1);
            addv[lson]+=addv[o];
            addv[rson]+=addv[o];
            addv[o]=0;
        }
    }
    inline void optadd(int o,int l,int r,int ql,int qr,int k)
    {
        if (ql<=l&&r<=qr) 
        {
            sumv[o]+=k*(rc[o]-lc[o]+1);
            addv[o]+=k;
            return;
        }
        pushdown(o);
        if (ql<=mid) optadd(lson,l,mid,ql,qr,k);
        if (qr>mid) optadd(rson,mid+1,r,ql,qr,k);
        pushup(o);
    }
    inline int query(int o,int l,int r,int ql,int qr)
    {
        if (ql<=l&&r<=qr) return sumv[o];
        pushdown(o);
        int ans=0;
        if (ql<=mid) ans+=query(lson,l,mid,ql,qr);
        if (qr>mid) ans+=query(rson,mid+1,r,ql,qr);
        return ans;
    }
}tree;
int n,m,w,x,y,k;
int main()
{
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    tree.build(1,1,n);
    for (int i=1;i<=m;i++)
    {
        scanf("%lld",&w);
        if (w==1)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
            tree.optadd(1,1,n,x,y,k);
        }
        if (w==2)
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",tree.query(1,1,n,x,y));
        }
    }
}