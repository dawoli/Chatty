#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,k;
const int MAXN=1e6+5;
vector<pair<int,int>>edge[MAXN];
int dis[MAXN];
int vis[MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road,in","r",stdin); 
    freopen("road,out","w",stdin);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        dis[i]=MAXN;
        vis[i]=false;
    }
    for(int i=1;i<=m;i++){
         int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }
    int r;
    for(int i=1;i<=(n+1)*k;i++)
        cin>>r;
        dis[1]=0;
    for(int i=1;i<=n;i++){
            int minn=MAXN,t=0;
        for(int i=0;i<=n;i++){
            if(minn>dis[i]){
                minn=dis[i];
                t=i;
            }
        }
        vis[t]=1;
        for(auto j:edge[i]){
            if(dis[j.first]>j.second&&vis[j.first]==0)
                dis[j.first]=j.second;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=dis[i];
    cout<<ans;
    return 0;
}
