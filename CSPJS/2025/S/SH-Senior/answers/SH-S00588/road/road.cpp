#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y,z;
}st[1000020],nw[150020],qwq[150020];
int fa[10020],si,K,n,m,ans,rans,val[15][10020],vis[15];
bool cmp(node x,node y){
	return x.z<y.z;
}
int Find(int x){
	if(x==fa[x])
		return x;
	return fa[x]=Find(fa[x]);
}
void calc(int x){
//	cout<<"!!!"<<x<<"\n";
	int cnt=n-1;
	rans=0;
	for(int i=1;i<n;i++)
		qwq[i]=nw[i];
	for(int i=1;i<=K;i++)
		vis[i]=0;
	for(int i=0;i<K;i++)
		if(x&(1<<i))
			vis[i+1]=1,rans+=val[i+1][0];
	for(int i=1;i<=n;i++){
		int Min=10000000000,id=0;
		for(int j=1;j<=K;j++)
			if(vis[j]&&Min>val[j][i])
				id=j,Min=val[j][i];
		nw[++cnt]={i,id+n,Min};
	}
	sort(nw+1,nw+cnt+1,cmp);
	for(int i=1;i<=n+K;i++)
		fa[i]=i;
//	for(int i=1;i<=cnt;i++)
//		cout<<nw[i].x<<" "<<nw[i].y<<" "<<nw[i].z<<"\n";
	for(int i=1;i<=cnt;i++){
		int fx=Find(nw[i].x),fy=Find(nw[i].y);
		if(fx==fy)
			continue;
		fa[fx]=fy;
		rans+=nw[i].z;
	}
	bool flag=1;
	int tmp=Find(1);
	for(int i=1;i<=n+K;i++){
		if(i<=n&&Find(i)!=tmp)
			flag=0;
		if(i>n&&vis[i-n]&&Find(i)!=tmp)
			flag=0;
	}
	if(flag)
		ans=min(ans,rans);
	for(int i=1;i<=n-1;i++)
		nw[i]=qwq[i];
	for(int i=n;i<=cnt;i++)
		qwq[i]={0,0,1000000000};
}
void dfs(int x,int p){
	if(p==K+1){
		calc(x);
		return ;
	}
	dfs(x|(1<<(p-1)),p+1);
	dfs(x,p+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		st[i]={x,y,z};
	}
	sort(st+1,st+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fx=Find(st[i].x),fy=Find(st[i].y);
		if(fx==fy)
			continue;
		fa[fx]=fy;
		ans+=st[i].z;
		nw[++cnt]=st[i];
	}
	for(int i=1;i<=K;i++)
		for(int j=0;j<=n;j++)
			cin>>val[i][j];
	dfs(0,1);
	cout<<ans;
}
