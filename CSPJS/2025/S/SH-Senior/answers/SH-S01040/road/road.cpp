//mst最小生成树变种 
//枚举选择城镇化改造的乡村？ 
//最多10n条边 
//加入一个点 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+20;
const int M=1e6+9;
const ll INF=1e18+9;
int n,m,k; 
ll a[14][N];
struct edge{
	int to,nxt;
	ll w;
}e[2*M+20*N];
int hd[N],nE=0;
inline void add(int u,int v,ll w){
	e[++nE]=(edge){v,hd[u],w};
	hd[u]=nE;
}
struct node{
	int u;
	ll d;
	int from;
	bool operator<(const node&b) const{
		return d>b.d;
	}
};
bool vis[N];
int cnt[N];
ll d[N];
ll c[N];
bool disuse[N];
inline ll prim(){
	for(int i=1;i<=n+k;i++){
		cnt[i]=0;vis[i]=0;
		d[i]=INF;
	}
	ll ans=0;
	priority_queue<node> q; 
	q.push((node){1,0,0});
	d[1]=0;
	while(!q.empty()){
		int u=q.top().u;
		
		if(vis[u]){
			q.pop();
			continue;
		} 
		ans=ans+q.top().d;
//		cout<<u<<" "<<q.top().from<<endl;
		cnt[q.top().from]++;
		vis[u]=1;
		q.pop();
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(disuse[v]==0&&v>n) continue;
			if(vis[v]) continue;
			if(e[i].w<d[v]){
				d[v]=e[i].w;
				q.push((node){v,e[i].w,u});
			}
		}
	}
	return ans;
}
ll tag=0;
ll ans2=0;
bool flagg=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flagg=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			add(i+n,j,a[i][j]);
			add(j,i+n,a[i][j]);
//			e[++cnt]=(edge){i+n,j,a[i][j]};
		}	
	}
	if(!flagg){
		for(int i=1;i<=k;i++){
			disuse[i+n]=1;
		}
		ll ans=prim();
		for(int j=1;j<=k;j++){
			if(cnt[j+n]==0&&disuse[j+n]){
//					if(disuse[
				ans-=c[j];
				ans-=d[j+n];
			}
		}
		cout<<ans;
		return 0;
	}
	//怎么不被使用，第一种就是造成答案增大不用,第二种是被其它的凭替不用 
	ll ans=prim();
//	cout<<ans;
	ans2=ans;
	for(int i=1;i<=k;i++){
		disuse[i+n]=1;
		tag+=c[i];
		ll sum=prim();
//		cout<<sum<<" "<<tag<<endl;
		ll tmp=sum+tag;
		for(int j=1;j<=i;j++){
			if(cnt[j+n]==0&&disuse[j+n]){
//					if(disuse[
				tmp-=c[j];
				tmp-=d[j+n];
			}
		}
//		cout<<tmp<<endl;
		if(tmp>=ans2){
			disuse[i+n]=0;
			tag-=c[i];
		}
		else{
			for(int j=1;j<=i;j++){
				if(cnt[j+n]==0&&disuse[j+n]){
//					if(disuse[
				disuse[j+n]=0;
				tag-=c[j];
				sum-=d[j+n];
				}
			}
//			cout<<i<<" "<<ans2<<endl;
			ans2=min(ans2,sum+tag);
		}
	}
	cout<<ans2;
//	disuse[2+n]=1;
//	cout<<prim();
//	for(int i=1;i<=n+k;i++){
//		cout<<cnt[i]<<" ";
//	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5	
4 3 4
*/
