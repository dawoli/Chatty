#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll f[10050],c[20],fw[20][10010];
vector< array<ll,3> > E;
vector< array<ll,3> > treeEdge[1010];

ll find(ll p){
    if(f[p]!=p) f[p]=find(f[p]);
    return f[p];
}

ll check_kr(ll msk){
    ll res=0;
    for(int i=1;i<=n+k;i++)
        f[i]=i;
    for(ll i=0;i<E.size();i++){
        ll w=E[i][0],u=E[i][1],v=E[i][2];
        if(find(u)==find(v)) continue;
        res+=w;f[find(u)]=find(v);
        treeEdge[msk].push_back({w,u,v});
    }
    E.clear();
    return res;
}

void solve(){
	cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        E.push_back({w,u,v});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>fw[i][j];
    }
    sort(E.begin(),E.end());
    ll ans=check_kr(0);
    for(int i=1;i<(1<<k);i++){
        ll lstmsk,addTown,extraCost=0;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                lstmsk=i^(1<<(j-1));
                addTown=j;
                break;
            }
        }
        for(int j=1;j<=k;j++)
            if((i>>(j-1))&1)
                extraCost+=c[j];
        for(auto nxt:treeEdge[lstmsk]) E.push_back(nxt);
        for(int j=1;j<=n;j++)
            E.push_back({fw[addTown][j],j,addTown+n});
        sort(E.begin(),E.end());
        ans=min(ans,check_kr(i)+extraCost);
    }
    cout<<ans<<endl;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll T;T=1;while(T--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}