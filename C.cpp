int ksm(int a,int b,int p=mo,int res=1)
{
    for( ; b ; a=a*a%p, b>>=1) if(b&1) res=res*a%p;
    return res; 
}
int fac[N],inv[N];
void init(int n=N-2)
{
    inv[0]=fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mo;
    inv[n]=ksm(fac[n],mo-2);
    for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mo;
}
int C(int n,int m)
{
    return fac[n]*inv[m]%mo*inv[n-m]%mo;
}