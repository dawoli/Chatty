#include<bits/stdc++.h>
using namespace std;
const int M=1e7+5,N=1e4+2;
int n,m,k;
struct edge{
    int u,v,w;
};
bool cmp(edge a,edge b){
    return a.w<b.w;
}
edge e[M];
int fa[N];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void solve1(){
    
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        if(find(u)==find(v))continue;
        fa[find(v)]=find(u);
        ans+=e[i].w;
    }
    cout<<ans<<'\n';
}
int a[15][10005];
bool chose[15];
int ans2=-1;
int prim(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        if(u>n&&chose[u-n]==0)continue;
        if(v>n&&chose[v-n]==0)continue;
        if(find(u)==find(v))continue;
        fa[find(v)]=find(u);
        ans+=e[i].w;
    }
    return ans;
}
void dfs(int u,int sum){
    if(u==k+1){
        //cout<<sum<<" ";
        if(ans2==-1){
            ans2=prim()+sum;
            cout<<sum<<" "<<prim()+sum<<'\n';
        }
        else if(ans2>=prim()+sum){
            ans2=prim()+sum;
            cout<<sum<<" "<<prim()+sum<<'\n';
            //cout<<sum<<" ";
        }
        return;
    }
    chose[u]=1;
    dfs(u+1,sum+a[u][0]);
    chose[u]=0;
    dfs(u+1,sum);
}
void solve2(){
    
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>a[i][0];
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            e[++m]={n+i,j,a[i][j]};
        }
    }
    k--;
    sort(e+1,e+m+1,cmp);
    dfs(1,0);
    cout<<ans2<<'\n';
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
        solve1();
    }else {
        solve2();
    }
}