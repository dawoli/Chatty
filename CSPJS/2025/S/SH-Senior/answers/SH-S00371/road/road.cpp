#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> > road[10050],a[11];
ll length[10050];
bool vis[10050];
priority_queue<pair<ll,ll> > q;
int n,m,k,f;
ll c[11];
ll bfs(int root){
    ll ans=0,cnt=1;
    vis[root]=true;
    for(int i=0;i<length[root];i++){
        q.push(road[root][i]);
    }
    while(!q.empty()){
        ll w=q.top().first,v=q.top().second;q.pop();
        if(vis[v]) continue;
        for(int i=0;i<length[v];i++){
            if(!vis[road[v][i].second]) q.push(road[v][i]);
        }
        vis[v]=true;
        cnt++;
        ans+=1000000000-w;
        if(cnt==n+f) break;
    }
    return ans;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        road[u].push_back(make_pair(1000000000-w,v));
        road[v].push_back(make_pair(1000000000-w,u));
        length[u]++;length[v]++;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]==0){
            f++;
            for(int j=1,b;j<=n;j++){
                cin>>b;
                road[n+i].push_back(make_pair(1000000000-b,j));
                road[j].push_back(make_pair(1000000000-b,n+i));
                length[n+i]++;length[j]++;
            }
        }
    }
    cout<<bfs(1);
    return 0;
}
