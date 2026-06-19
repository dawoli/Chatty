#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
constexpr int N = 1e4+7;
constexpr int M = 1e6+7;
constexpr int K = 11;
using ll = long long;
int n,m,k;
struct Edge{
    int u,v;
    ll w;
};
std::vector<Edge> my_edges;
int pa[N<<1];
int tot;
void quick(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}
ll cst[K][N],cty[K];
int find_root(int u){
    return pa[u]==u?u:(pa[u]=find_root(pa[u]));
}
int block_cnt;
ll Kruskal(){
    block_cnt = tot;
    for(int i=1;i<=tot;++i)pa[i]=i;
    std::sort(my_edges.begin(),my_edges.end(),[](const Edge&A,const Edge&B){
        return A.w < B.w;
    });
    ll res=0;
    for(const auto &now_edge : my_edges){
        int u=now_edge.u,v=now_edge.v;
        // std::cout<<now_edge.u<<" "<<now_edge.v<<" "<<now_edge.w<<std::endl;
        int ru=find_root(u),rv=find_root(v);
        if(ru==rv)continue;
        pa[ru]=rv;
        --block_cnt;
        res+=now_edge.w;
        // std::cout<<now_edge.w<<" "<<res<<std::endl;
        if(block_cnt==1)break;
    }
    return res;
}
int main(){
    quick();
    std::freopen("road.in","r",stdin);
    std::freopen("road.out","w",stdout);
    std::cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v;
        ll w;
        std::cin>>u>>v>>w;
        my_edges.push_back((Edge){u,v,w});
    }
    tot=n+k;
    for(int i=1;i<=k;++i){
        std::cin>>cty[i];
        for(int j=1;j<=n;++j){
        std::cin>>cst[i][j];
    }}
    if(k==0){
        std::cout<<Kruskal()<<std::endl;
        return 0;
    }
    bool tag=1;
    if(tag){
        ll ans=0;
        for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)my_edges.push_back((Edge){(n+i),j,cst[i][j]});
        ans=Kruskal();
        std::cout<<ans<<std::endl;
        return 0;
    }
    return 0;
}