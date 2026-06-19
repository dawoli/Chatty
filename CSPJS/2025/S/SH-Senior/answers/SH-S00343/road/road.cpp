#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e4+9,M=2e6+9,INF=1e10+9;
bool OK[M],isn[N];
struct ed{
	ll u,v,w;
}edge[M],edge1[N];
bool cmp(const ed&a,const ed&b){
	return a.w<b.w;
}
ll n,m,k,cnt,a[19][N],c[N],ans;
ll sz[N],rt[N],va[N];
vector<ll>son[N];
ll Kruskal(ll m){
	ll ans=0,cnt=0,num=0;
	sort(edge+1,edge+m+1,cmp);
	for(ll i=0;i<=2*n;i++)
		sz[i]=rt[i]=0,son[i]={};
	for(ll i=1;i<=m;i++){
		ll u=edge[i].u,v=edge[i].v,w=edge[i].w;
//		cout<<u<<" "<<v<<" "<<w<<" "<<rt[u]<<" "<<rt[v]<<endl;
		if(rt[u]==0)swap(u,v),swap(edge[i].u,edge[i].v);
		if(rt[u]==0&&rt[v]==0){
			num++;
			ans+=w;
			OK[i]=1;
			sz[++cnt]=2;
			rt[u]=rt[v]=cnt;
			son[cnt].push_back(u);
			son[cnt].push_back(v);
		}
		else 
		if(rt[u]!=rt[v]){
			num++;
			ans+=w;
			OK[i]=1;
			u=rt[u],v=rt[v];
			if(sz[v]>sz[u])swap(u,v),swap(edge[i].u,edge[i].v);
			if(v==0){
				sz[u]+=1;
				son[u].push_back(edge[i].v);
				rt[edge[i].v]=u;
//				cout<<ans<<endl;
				continue;
			}
			sz[u]+=sz[v];
			for(ll j=0;j<son[v].size();j++){
				ll now=son[v][j];
				son[u].push_back(now);
				rt[now]=u;
			}
		}
//		cout<<ans<<endl;
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<rt[edge[i].u]<<" "<<rt[edge[i].v]<<endl<<endl;
	}
	return ans;
}
void baoli(ll now,bool flag){
	if(now==k+1&&flag){
		ll sum=0;
		for(ll i=1;i<=n;i++)
			va[i]=INF;
		for(ll i=1;i<=k;i++){
//			cout<<isn[i]<<" ";
			if(isn[i]){
				sum+=c[i];
				for(ll j=1;j<=n;j++)
					va[j]=min(va[j],a[i][j]);
			}
		}
//		cout<<" "<<sum<<endl;
		for(ll i=1;i<=n-1;i++)
			edge[i]=edge1[i];
		for(ll i=n;i<=2*n-1;i++)
			edge[i]=ed{i-n+1,n+1,va[i-n+1]};
//		for(int i=1;i<=2*n-1;i++){
//				ll u=edge[i].u,v=edge[i].v,w=edge[i].w;
//				cout<<u<<" "<<v<<" "<<w<<endl;
//		}
//		cout<<Kruskal(2*n-1)+sum<<endl<<endl;
		ans=min(ans,Kruskal(2*n-1)+sum);
//		cout<<endl;
		return;
	}
	if(now==k+1)return;
	baoli(now+1,flag);
	isn[now]=1;
	baoli(now+1,1);
	isn[now]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		edge[i]=ed{u,v,w};
	}
	ans=Kruskal(m);
//	cout<<ans<<endl;
	for(ll i=1;i<=m;i++){
		if(OK[i])edge1[++cnt]=edge[i];
	}
//	cout<<cnt<<endl;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)
			cin>>a[i][j];
	}
	baoli(1,0);
	cout<<ans<<endl;
	return 0;
}
