#include<bits/stdc++.h>
using namespace std;
int n,m;
int aa[200005],a[200005],X[4],c[200005];
int u[200005];
int fir[20],K;
bitset<300005>d;
int w[300005];long long sum[300005];
long long ans;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int i,j,k,T;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%d",&aa[i]);
    for(i=1;i<=m;i++){
        scanf("%d",&c[i]);
        while((1<<u[i])<c[i])u[i]++;
    }
    while((1<<K)<n)K++;
    for(i=K;i;i--)
        fir[i]=(fir[i+1]<<1)+1;
    for(i=1;i<=K;i++){
        char ch;
        for(j=1;j<=(1<<(K-i));j++){
            for(ch=getchar();ch!='0'&&ch!='1';ch=getchar());
            d[fir[i+1]+j]=ch-'0';
        }
    }
    for(i=1;i<=(1<<K);i++)
        w[fir[1]+i]=sum[fir[1]+i]=i;
    for(i=fir[1];i;i--)
        sum[i]=sum[i<<1]+sum[(i<<1)|1];
    cin>>T;
    while(T--){
        scanf("%d%d%d%d",&X[0],&X[1],&X[2],&X[3]);
        for(i=1;i<=n;i++)
            a[i]=aa[i]^X[i&3];
        for(i=1;i<=K;i++){
            for(j=1;j<=(1<<(K-i));j++){
                int nw=fir[i+1]+j;
                if(d[nw]){
                    if(a[w[(nw<<1)|1]]>=i)w[nw]=w[(nw<<1)|1];
                    else w[nw]=w[nw<<1];
                }else{
                    if(a[w[nw<<1]]>=i)w[nw]=w[nw<<1];
                    else w[nw]=w[(nw<<1)|1];
                }
            }
        }
        ans=0;
        for(i=1;i<=m;i++){
            if((1<<u[i])==c[i]){
                ans^=i*1ll*w[fir[u[i]+1]+1];
                continue;
            }
            long long p=c[i]+1;
            int cur[20],cnt=0;
            int nw=fir[1]+c[i]+1;
            for(j=1;j<=u[i];j++){
                if(!(nw&1)){
                    nw>>=1;int b=0;
                    if(!d[nw]){
                        for(k=cnt;k;k--)
                            if(a[cur[k]]<j){
                                swap(cur[k],cur[cnt]);
                                cnt--;b=1;
                            }
                        if(b||p)p+=sum[(nw<<1)|1];
                    }else p+=sum[(nw<<1)|1];
                }else{
                    nw>>=1;
                    if(d[nw]){
                        int b=0;
                        for(k=cnt;k;k--)
                            if(a[cur[k]]<j){
                                swap(cur[k],cur[cnt]);
                                cnt--;b=1;
                            }
                        if(b||p){
                            cur[++cnt]=w[nw<<1];
                        }
                    }else{
                        if(a[w[nw<<1]]>=j)
                            cur[1]=w[nw<<1],cnt=1,p=0;
                    }
                }
            }
            while(cnt--)
                p+=cur[cnt+1];
            ans^=p*i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}