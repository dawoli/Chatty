#include <bits/stdc++.h>
using namespace std;
vector<int> g;
int u,v,w,n,m,k,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g.push_back(w);
    }
    sort(g.begin(),g.end());
    for(int i=1;i<=n-1;i++){
        ans+=g[i];
    }
    cout<<ans;
    return 0;
}