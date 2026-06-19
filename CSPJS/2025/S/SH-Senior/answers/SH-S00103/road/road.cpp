#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,pair<int,int> > PLL;
int n,m,k,a[15][10010];
ll ans=1e14;
priority_queue<PLL,vector<PLL>,greater<PLL> > qu;
int fa[10010];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void add(int x,int y){
	if(find(x)==find(y)) return;
	fa[find(x)]=y;
}
ll belf(int cntk,priority_queue<PLL,vector<PLL>,greater<PLL> > qu){
	ll ans=0;
	for(int i=1;i<=n+cntk;i++) fa[i]=i;
	for(int i=1;i<n+cntk;i++){
		PLL pll;
		do{
			pll=qu.top();
			qu.pop();
		}while(find(pll.second.first)==find(pll.second.second));
		add(pll.second.first,pll.second.second);
		ans+=pll.first;
	}
	return ans;
}
void dfs(int ki,int cntk,priority_queue<PLL,vector<PLL>,greater<PLL> > qu,ll ans1){
	if(ki==k+1){
		ans=min(belf(cntk,qu)+ans1,ans);
		return;
	}
	dfs(ki+1,cntk,qu,ans1);
	for(int i=1;i<=n;i++){
		qu.push({a[ki][i],{n+cntk+1,i}});
	}
	dfs(ki+1,cntk+1,qu,ans1+a[ki][0]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		qu.push({w,{u,v}});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	dfs(1,0,qu,0);
	cout<<ans;
	return 0;
}

