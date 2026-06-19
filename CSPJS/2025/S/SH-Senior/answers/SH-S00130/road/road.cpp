#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,ans;
int fa[100010];
long long a[10][100010];
struct node{
	long long u,v,w;
	bool operator < (node x) const {
	    return w>x.w;
	}
};
vector<node> edg;
priority_queue<node> q;

//16:20 4X4=16 tps
//16:50 4X12=48 tps

int find(int o){
	if(o==fa[o])return o;
	return fa[o]=find(fa[o]);
}

void planA(){
	for(int i=0;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<=m;i++){
		node r=q.top();
		q.pop();
		int u=r.u,v=r.v;
		if(find(u)!=find(v)){
			fa[find(u)]=v;
			ans+=r.w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		planA();
		return 0;
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		q.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			q.push({n+i,j,a[i][j]});
		}
	}
	for(int i=0;i<=10011;i++)fa[i]=i;
	for(int i=1;i<=m+k*n;i++){
		node r=q.top();
		q.pop();
		long long u=r.u,v=r.v;
		if(find(u)!=find(v)){
			fa[find(u)]=v;
			ans+=r.w;
			cnt++;
		}
		if(cnt==n+k-1)break;
	}
	cout<<ans;
}
