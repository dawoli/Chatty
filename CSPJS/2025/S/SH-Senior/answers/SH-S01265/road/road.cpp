#include <bits/stdc++.h>
using namespace std;
const int N=10035;
const int M=1000035;
const int K=11;
//const bool MyDEBUG=false;
int n,m,k;
struct Road{
	int u;
	int v;
	long long w;
	bool operator<(const Road& rd) const{
		return w<rd.w;
	}
} eq[M],ed[N];
int fa[N],fa_cnt[N];
long long c[K];
pair<long long,int> a[K][N];
//n+1  ~ n+10 : 乡村
//n+11 ~ n+20 : 乡村虚拟点 
bool need_vis(int q,int S){
	return (bool)(S&(1<<(q-1)));
}
int find(int p){
	int fp=p;
	while(fa[p]!=p) p=fa[p];
	while(fa[fp]!=fp){
		int tmp=fp;
		fp=fa[fp];
		fa[tmp]=p;
	}
	return p;
}
bool merge(int i,int j){
	if(find(i)==find(j)) return false;
	if(fa_cnt[find(i)]<fa_cnt[find(j)]){
		int tmp=i;
		i=j;
		j=tmp;
	}
	fa_cnt[find(i)]+=fa_cnt[find(j)];
	fa[find(j)]=find(i);
	return true;
}
int rp[K],vis[K];
//rp++;
long long Kruskal(int S){
	int cnt=0,now_vis=0;
	Road now_rd;
	for(int i=1;i<=10;i++) if(need_vis(i,S)) rp[++cnt]=i;
//				if(MyDEBUG) cout<<"Now Visiting: ";
//				if(MyDEBUG){
//					for(int i=1;i<=cnt;i++) cout<<n+rp[i]<<",";
//					for(int i=1;i<=cnt;i++) cout<<n+rp[i]+10<<",";
//				}
//				if(MyDEBUG) cout<<"\n";
	for(int i=0;i<=10;i++) vis[i]=1;
	long long ans=0;
	for(int i=1;i<=n+20;i++){
		fa[i]=i;
		fa_cnt[i]=1;
	}
	int i;
	int cntm=0;
	while(cntm<n+cnt*2-1){
		now_vis=0;
		now_rd=ed[vis[0]];
		for(int j=1;j<=cnt;j++){
			i=rp[j];
			if(((!now_vis)&&a[i][vis[i]].first<ed[vis[0]].w)||(now_vis&&a[i][vis[i]].first<a[now_vis][vis[now_vis]].first)){
				now_vis=i;
				now_rd.u=n+i;
				now_rd.v=a[i][vis[i]].second;
				now_rd.w=a[i][vis[i]].first;
			}
		}
		vis[now_vis]++;
		if(merge(now_rd.u,now_rd.v)){
			cntm++;
			ans+=now_rd.w;
//			if(MyDEBUG) cout<<"   add edge "<<now_rd.u<<"--"<<now_rd.v<<" L="<<now_rd.w<<"\n";
		}
	}
//	if(MyDEBUG) cout<<"ans="<<ans<<"\n\n";
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>eq[i].u>>eq[i].v>>eq[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			a[i][j].second=j;
			cin>>a[i][j].first;
		}
		for(int j=n+1;j<=n+20;j++) a[i][j]=make_pair(1000000007ll,j);
		a[i][n+10+i]=make_pair(c[i],n+10+i);
	}
	sort(eq+1,eq+m+1);
//	cout<<"Input endnd\n";
//	if(MyDEBUG){
//		cout<<"edges are: \n"; for(int i=1;i<=m;i++) cout<<eq[i].u<<"-"<<eq[i].v<<" L="<<eq[i].w<<"\n";
//	}
	long long ans=0;
	int cntm=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;cntm<n-1&&i<=m;i++){
		if(merge(eq[i].u,eq[i].v)){
			cntm++;
			ed[cntm]=eq[i];
			ans+=eq[i].w;
		}
	}
//	if(MyDEBUG) cout<<"without:"<<ans<<"\n";
//	cout<<"MGT finded\n";
	//找最小生成树并去掉除最小生成树外的所有边 
	for(int i=1;i<=k;i++) sort(a[i]+1,a[i]+n+21);
//	if(MyDEBUG){
//		for(int i=1;i<=k;i++){
//		cout<<"for "<<i<<", ";
//		cout<<"edges are: \n"; for(int j=1;j<=n+10+k;j++) if(a[i][j].first!=1000000007ll) cout<<n+i<<"-"<<a[i][j].second<<" L="<<a[i][j].first<<"\n";
//		}
//	}
	for(int S=0;S<(1<<k);S++){
		ans=min(ans,Kruskal(S));
	}
	cout<<ans;
	return 0;
}
