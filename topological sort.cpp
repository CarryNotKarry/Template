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
int in[N],cnt,head[N],u,v,w,n,m,x,y;
struct node
{
    int to,next;
}edge[N<<1];
inline void add(int x,int to)
{
    edge[++cnt].to=to;
    edge[cnt].next=head[x];
    head[x]=cnt;
}
vector<int> tp;
int topo_cnt[N];
inline void topo()
{
    queue<int> Q;
    int t=0;
    for (int i=1;i<=n;i++)
        if (!in[i])
        {
            Q.push(i);
            topo_cnt[i]=++t;
            tp.push_back(i);
        }
    while (!Q.empty())
    {
        int now=Q.front();Q.pop();
        for (int i=head[now];i;i=edge[i].next)
        {
            int y=edge[i].to;
            in[y]--;
            if (!in[y])
            {
                Q.push(y);
                topo_cnt[y]=++t;
                tp.push_back(y);
            }
        }
    }
    if (t!=n) cout<<"It is not DAG!";
    else 
        for (auto i:tp) cout<<i<<" ";
    cout<<endl;
}
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
        cin>>u>>v;
        add(u,v);
        in[v]++;
    }
    topo();
    return 0;
}