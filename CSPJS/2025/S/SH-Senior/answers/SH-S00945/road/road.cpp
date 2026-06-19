#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
long long n,m,p,tt,mm,tot,ans,a[N],b[N],e[N],f[N],g[N],s[N],u[N],v[N],w[N],x[N],y[N],z[N];
bool cmp1(const long long &aa,const long long &bb){
    return z[aa]<z[bb];
}
bool cmp2(const long long &aa,const long long &bb){
    return w[aa]<w[bb];
}
int ff(int xx){
    if(f[xx]==xx)return xx;
    else return f[xx]=ff(f[xx]);
}
int read(){
    int rtn=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){
        rtn=rtn*10+ch-'0';
        ch=getchar();
    }
    return rtn;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();p=read();
    for(int i=1;i<=m;i++){
        x[i]=read();y[i]=read();z[i]=read();
        s[i]=i;
    }
    sort(s+1,s+m+1,cmp1);
    for(int i=1;i<=n;i++){
        f[i]=i;
        g[i]=1;
        b[i]=1;
    }
    for(int i=1;i<=m;i++){
        if(ff(x[s[i]])!=ff(y[s[i]])){
            tot++;
            u[tot]=x[s[i]];
            v[tot]=y[s[i]];
            w[tot]=z[s[i]];
            e[tot]=tot;
            ans+=z[s[i]];
            if(b[f[x[s[i]]]]<b[f[y[s[i]]]]){
                b[f[y[s[i]]]]+=b[f[x[s[i]]]];
                f[f[x[s[i]]]]=f[y[s[i]]];
            }
            else {
                b[f[x[s[i]]]]+=b[f[y[s[i]]]];
                f[f[y[s[i]]]]=f[x[s[i]]];
            }
        }
    }
    for(int i=1;i<=p;i++){
        a[i]=read();
        for(int j=1;j<=n;j++){
            tot++;
            u[tot]=i+n;
            v[tot]=j;
            w[tot]=read();
            e[tot]=tot;
        }
    }
    sort(e+1,e+tot+1,cmp2);
    for(int I=1;I<(1<<p);I++){
        for(int i=1;i<=n+p;i++){
            f[i]=i;
            b[i]=1;
        }
        tt=0;mm=n;
        for(int i=1;i<=p;i++){
            if(I&(1<<(i-1))){
                tt+=a[i];
                g[i+n]=1;
                mm++;
            }
            else g[i+n]=0;
        }
        mm--;
        for(int i=1;mm;i++){
            if(g[u[e[i]]]&&ff(u[e[i]])!=ff(v[e[i]])){
                tt+=w[e[i]];
                if(b[f[u[e[i]]]]>b[f[v[e[i]]]]){
                    b[f[u[e[i]]]]+=b[f[v[e[i]]]];
                    f[f[v[e[i]]]]=f[u[e[i]]];
                }
                else{
                    b[f[v[e[i]]]]+=b[f[u[e[i]]]];
                    f[f[u[e[i]]]]=f[v[e[i]]];
                }
                mm--;
            }
        }
        ans=min(ans,tt);
    }
    printf("%lld\n",ans);
}
