#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e4+25,maxm=1e6+15,maxk=20;
ll n,m,k,ans,sum,c[maxk],sz[maxn],fa[maxn],p[maxk];
struct node{
	ll u,v,w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
}edg[maxm],cost[maxk][maxn];
vector<node> V,Vt;
ll find(ll x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
	x=find(x);y=find(y);
	if(sz[x]<sz[y]) swap(x,y);
	fa[y]=x;
	return;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n+k;i++){
		sz[i]=1;fa[i]=i;
	}
	for(ll i=1;i<=m;i++) cin>>edg[i].u>>edg[i].v>>edg[i].w;
	sort(edg+1,edg+m+1,cmp);
	for(ll i=1;i<=m;i++){
		if(find(edg[i].u)!=find(edg[i].v)){
			merge(edg[i].u,edg[i].v);
			V.push_back(edg[i]);
			ans+=edg[i].w;
		}
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>cost[i][j].w;
			cost[i][j].u=i+n;cost[i][j].v=j;
		}
	}
	for(ll i=1;i<=k;i++){
		sort(cost[i]+1,cost[i]+n+1,cmp);
	}
	priority_queue<node> Q;
	for(ll t=1;t<(1<<k);t++){
		for(ll i=1;i<=n+k;i++){
			sz[i]=1;fa[i]=i;
		}
		sum=0;
		p[0]=0;
		for(ll j=1;j<=k;j++) p[j]=1;
		Q.push(V[0]);
		for(ll j=1;j<=k;j++){
			ll mask=(1<<(j-1));
			if((t&mask)>0){
				sum+=c[j];Q.push(cost[j][1]);
			}
		}
		while(!Q.empty()){
			auto x=Q.top();
			ll pos=x.u-n;
			pos=max(pos,0ll);
			Vt.push_back(x);
//			cerr<<x.u<<","<<x.v<<","<<x.w<<"\n";
			Q.pop();
			if((p[pos]<n)&&(pos!=0)) Q.push(cost[pos][++p[pos]]);
			if(pos==0&&p[pos]<n-2) Q.push(V[++p[pos]]);
		}
		for(ll i=0;i<Vt.size();i++){
			if(find(Vt[i].u)!=find(Vt[i].v)){
				merge(Vt[i].u,Vt[i].v);
				sum+=Vt[i].w;
			}
		}
//		cerr<<sum<<"\n";
		ans=min(ans,sum);
		Vt.clear();
	}
	cout<<ans;
	return 0;
}
