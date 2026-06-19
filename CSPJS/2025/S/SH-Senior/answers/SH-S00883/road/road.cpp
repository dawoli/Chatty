#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
struct node{
	int u,v,w;
};
bool cmp(node x,node y){
	return x.w<y.w;
}
int d[500005],ll[15][10005];
int n,m,k;

vector<node> e;

int find(int x){
	if(d[x]!=x)d[x]=find(d[x]);
	return d[x];
}
void merge(int x,int y){
	d[x]=find(y);
	d[y]=find(x);
}
int ans=INF;
int kruscal(vector<node> e){
	int sum=0;
	for(auto ed:e){
		int u=ed.u,v=ed.v,w=ed.w;
		if(find(u)!=find(v)){
			sum+=w;
			merge(u,v);
		}
	}
	return sum;
}
int vis[15];

void dfs(int step){
	if(step==k){
		vector<node> e1=e;
		int ss=0;
		for(int i=0;i<step;i++){
			if(vis[i]==1){
				for(int j=1;j<=n;j++){
					e1.push_back({j,n+i+1,ll[i][j]});
				}
				ss+=ll[i][0];
			}
		}
		sort(e1.begin(),e1.end(),cmp);
		for(int i=1;i<=n;i++)d[i]=i;
		int kk=kruscal(e1)+ss;
		ans=min(ans,kk);
		return;
	}
	for(int i=1;i<=2;i++){
		vis[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({min(u,v),max(u,v),w});
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<=n;j++)
			cin>>ll[i][j];
	dfs(0);
	cout<<ans;
	return 0;
}
