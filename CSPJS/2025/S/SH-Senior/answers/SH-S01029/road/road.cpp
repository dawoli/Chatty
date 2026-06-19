#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e6+5;
const int MAXK=15;
struct node{
    int u,v,w;
}eg[MAXM],neg[MAXM];
int tot=0;
int n,m,k;
int c[MAXK];
int a[MAXK][MAXN];

long long ans=1e18;

int fa[MAXN];
int getf(int x){
    if(x==fa[x]){
        return x;
    }
    return fa[x]=getf(fa[x]);
}
long long kruskal(bool se,int kk){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    long long ret=0;
    for(int i=1;i<=m;i++){
        if(!se){
            if(neg[i].u>n){
                if(((kk>>(neg[i].u-n-1))&1)==0){
                    continue;
                }
            }
            if(neg[i].v>n){
                if(((kk>>(neg[i].v-n-1))&1)==0){
                    continue;
                }
            }
        }
        int fau=getf(neg[i].u);
        int fav=getf(neg[i].v);
        if(fau==fav){
            continue;
        }
        fa[fau]=fav;
        ret+=neg[i].w;
        if(se){
            eg[++tot]=neg[i];
        }
    }
    return ret;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&neg[i].u,&neg[i].v,&neg[i].w);
    }
    sort(neg+1,neg+1+m,[](node x,node y){
        return x.w<y.w;
    });
    ans=min(ans,kruskal(true,-1));
    tot=0;
    for(int j=1;j<n;j++){
        neg[++tot]=eg[j];
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            tot++;
            neg[tot].u=n+i;
            neg[tot].v=j;
            neg[tot].w=a[i][j];
        }
    }
    m=tot;
    sort(neg+1,neg+1+m,[](node x,node y){
        return x.w<y.w;
    });
    // cerr<<ans<<"\n";
    for(int i=1;i<(1<<k);i++){
        long long tmp=0;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                tmp+=c[j];
            }
        }
        ans=min(ans,tmp+kruskal(false,i));
    }
    printf("%lld",ans);
    return 0;
}
