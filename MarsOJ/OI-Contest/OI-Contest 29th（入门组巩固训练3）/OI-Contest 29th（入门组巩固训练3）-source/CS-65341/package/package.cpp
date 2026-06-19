#include<bits/stdc++.h>
using namespace std;
int v[1000005],t[10005],w[10005],n,m,k,ans=INT_MAX;
void dfs(int dep,int we,int cost){
    if(dep>n){
        ans=min(ans,cost+v[we]);
        return;
    }
    if(we+w[dep]<=m) dfs(dep+1,we+w[dep],cost);
    dfs(dep+1,w[dep],cost+v[we]);
}
int main(){
    freopen("package.in","r",stdin);
    freopen("package.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>t[i]>>w[i];
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
