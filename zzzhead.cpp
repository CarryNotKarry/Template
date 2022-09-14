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

inline void Case_Test()
{
    
}

signed main() 
{
    #ifndef ONLINE_JUDGE
        //freopen("/Users/carry/test/IO/in.txt","r",stdin);
        //freopen("/Users/carry/test/IO/out.txt","w",stdout);
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