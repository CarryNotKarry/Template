/*
 ██████╗ █████╗ ██████╗ ██████╗ ██╗   ██╗
██╔════╝██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝
██║     ███████║██████╔╝██████╔╝ ╚████╔╝ 
██║     ██╔══██║██╔══██╗██╔══██╗  ╚██╔╝  
╚██████╗██║  ██║██║  ██║██║  ██║   ██║   
 ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   
*/

#include<stack>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<deque>
#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<iomanip>
#include<bitset>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-8
#define sqr(x) ((x)*(x))
#define int long long
#define PII pair<int,int> 
#define lowbit(x) ((x)&(-x))
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = "<< y << endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define Yes cout<<"Yes"<<endl
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}
template <typename T, typename S> inline bool chkmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <typename T, typename S> inline bool chkmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
template<class T,class u>
ostream& operator<<(ostream& os,const pair<T,u>& p){
	return os<<"{"<<p.first<<","<<p.second<<"}";
}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
	os<<"{";
    int sz = v.size();
	for(int i=0;i<sz;i++) os<<v[i]<<", "[i==sz-1];
	return os<<"}";
}
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
inline int gcd(int a,int b){return b ? gcd(b , a % b) : a ;}
inline int qpow(int a,int b,int c){int res=1%c;a%=c;while(b>0){if(b&1)res=res*a%c;a=a*a%c;b>>=1;}return res;}
inline int popcount(int x){return __builtin_popcount(x);}//number of '1'
inline int clz(int x){return __builtin_clz(x);}//left zero num
inline int ctz(int x){return __builtin_ctz(x);}//right zero num
inline int lcm(int x,int y) {return x/gcd(x,y)*y;}
const int inf=0x3f3f3f3f;
const int INF=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int inv2=499122177;
const int N = 3e5+7;
int n,m,k,ans,x,y,q,cnt,a[N],b,p;
string s;
bool vis[N];
char c;
/*
1.插入数值 x。
2.删除数值 x(若有多个相同的数，应只删除一个)。
3.查询数值 x 的排名(若有多个相同的数，应输出最小的排名)。
4.查询排名为 x 的数值。
5.求数值 x 的前驱(前驱定义为小于 x 的最大的数)。
6.求数值 x 的后继(后继定义为大于 x 的最小的数)。
*/
struct Splay_Tree {
    int fa[N], cnt[N], ch[N][2], val[N], sz[N];
    int root, tot;
    #define ls(x) ch[(x)][0]
    #define rs(x) ch[(x)][1]
    inline void update(int x) {
        sz[x] = sz[ls(x)] + sz[rs(x)] + cnt[x];
    }
    inline void rotate(int x) {
        int y = fa[x];
        int z = fa[y];
        int k = (rs(y)==x);
        ch[z][(rs(z)==y)] = x;
        fa[x] = z;
        ch[y][k] = ch[x][k^1];
        fa[ch[x][k^1]] = y;
        ch[x][k^1] = y;
        fa[y] = x;
        update(y);update(x);
    }
    inline void splay(int x,int s) {
        while (fa[x]!=s) {
            int y = fa[x], z = fa[y];
            if (z!=s)
                (ls(z)==y)^(ls(y)==x)?rotate(x):rotate(y);
            rotate(x);
        }
        if (s==0) root = x;
    }
    inline void find(int x) {
        int u = root;
        if (!u) return ;
        while (ch[u][x>val[u]] && x!=val[u])
            u = ch[u][x>val[u]];
        splay(u,0);
    }
    inline void insert(int x) {
        int u = root, f = 0;
        while (u && val[u]!=x) {
            f = u;
            u = ch[u][x>val[u]];
        }
        if (u) cnt[u]++;
        else{
            u = ++tot;
            if (f) ch[f][x>val[f]] = u;
            ls(u) = rs(u) = 0;
            sz[tot] = 1; cnt[tot] = 1;
            val[tot] = x; fa[tot] = f;
        }
        splay(u,0);
    }
    inline int Next(int x,int f) {
        find(x);
        int u = root;
        if (val[u]>x && f)
            return u;
        if (val[u]<x && !f)
            return u;
        u = ch[u][f];
        while (ch[u][f^1])
            u = ch[u][f^1];
        return u;
    }
    inline void Delete(int x)
    {
        int last = Next(x,0);
        int nxt = Next(x,1);
        splay(last, 0);
        splay(nxt, last);
        int del = ls(nxt);
        if (cnt[del]>1){
            cnt[del]--;
            splay(del, 0);
        }
        else
            ls(nxt) = 0;
    }
    inline int kth(int x) {
        int u = root;
        if (sz[u]<x) 
            return 0;
        while (1){
            int y = ls(u);
            if (x>sz[y]+cnt[u]){
                x -= sz[y] + cnt[u];
                u = rs(u);
            }
            else if (sz[y]>=x)
                u = y;
            else 
                return val[u];
        }
    }
    inline int pre(int x) {
        return val[Next(x,0)];
    }
    inline int nxt(int x) {
        return val[Next(x,1)];
    }
    inline int rank(int x) {
        find(x);
        return sz[ls(root)];
    }
    #undef ls
    #undef rs
}tr;

inline void Case_Test()
{
    cin>>n;
    tr.insert(1e9);
    tr.insert(-1e9);
    while(n--)
    {
        int op,x;
        cin>>op>>x;
        if (op==1)
            tr.insert(x);
        if (op==2)
            tr.Delete(x);
        if (op==3)
            cout<<tr.rank(x)<<endl;
        if (op==4)
            cout<<tr.kth(x+1)<<endl;;
        if (op==5)
            cout<<tr.pre(x)<<endl;
        if (op==6)
            cout<<tr.nxt(x)<<endl;
    }
}

signed main() 
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/carry/test/IO/in.txt","r",stdin);
        freopen("/Users/carry/test/IO/out.txt","w",stdout);
        clock_t start, end;
        start = clock();
    #endif
    IOS
    int _=1;
    //cin>>_;
    while (_--)
    {
        Case_Test();
    }

    #ifndef ONLINE_JUDGE
        end = clock();
        cout << endl << "Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    #endif
}