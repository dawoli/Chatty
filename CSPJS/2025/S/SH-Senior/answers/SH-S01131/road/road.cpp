#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
    int u,v,w;
}g[1000010];
vector<int>ma[10010];
int n,m,k,a[1000010],ans,x,cnt;
bool akioi(Node x,Node y){
    return x.w<y.w;
}
bool dfs(int x,int y,int l){
	if(x==y)return 1;
	bool an=0;
	for(int i=0;i<ma[x].size();i++)
		if(ma[x][i]!=l)if(dfs(ma[x][i],y,x))an=1;
	return an;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>g[i].u>>g[i].v>>g[i].w;/*
    for(int i=1;i<=k;i++){
        cin>>x;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            if(a[j]==0)x=j;
        }
        for(int j=1;j<=n;j++){
            if(j==x)continue;
            m++;
            g[m].u=x,g[m].v=j,g[m].w=a[j];
        }
    }*/
    sort(g+1,g+m+1,akioi);
    for(int i=1;i<=m;i++){
        if(cnt==n-1)break;
        if(dfs(g[i].v,g[i].u,0))continue;
        ans+=g[i].w,cnt++;
        ma[g[i].v].push_back(g[i].u);
        ma[g[i].u].push_back(g[i].v);
    }
    cout<<ans;
	return 0;
}
