#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=509,P=998244353;
int n,m,a[N],sa[N],fac[N]; char str[N];
int f[2][N][N];
void upd(int &a,int b){
    (a+=b)>=P&&(a-=P);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    for(int i=fac[0]=1;i<N;i++) fac[i]=(LL)fac[i-1]*i%P;
    scanf("%d%d%s",&n,&m,str+1); m=n-m+1;
    // printf("m = %d\n",m);
    for(int i=1;i<=n;i++) str[i]^='0';
    for(int i=1,c;i<=n;i++) scanf("%d",&c),a[min(c,m)]++;
    sa[0]=a[0];
    for(int i=1;i<=m;i++) sa[i]=sa[i-1]+a[i];
    f[1][0][a[0]]=1;
    int cur=1,las=0,res=0;
    for(int i=1,v;i<=n+1;i++){
        for(int k=0;k<=n;k++) res=(res+(LL)f[cur][m][k]*fac[k])%P/* ,printf("%d %d %d\n",i,k,f[cur][m][k]) */;
        swap(cur,las);
        memset(f[cur],0,sizeof(f[cur]));
        if(i<=n) for(int j=0;j<m&&j<i;j++)
            for(int k=0;k<=sa[j];k++) if(v=f[las][j][k]){
                // printf("f %d %d %d %d\n",i,j,k,v);
                if(!str[i]){
                    upd(f[cur][j+1][k+a[j+1]],v);
                    continue;
                }
                if(k){
                    f[cur][j+1][k-1+a[j+1]]=(f[cur][j+1][k-1+a[j+1]]+(LL)v*k)%P;
                    f[cur][j][k-1]=(f[cur][j][k-1]+(LL)(P-v)*k)%P;
                }
                upd(f[cur][j][k],v);
            }
    }
    int tot=1;
    for(int i=1;i<=n;i++) tot=(LL)tot*i%P;
    printf("%d\n",(tot-res+P)%P);
    return 0;
}