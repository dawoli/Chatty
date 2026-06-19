#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+9;
const ll M=1e6+9;
const ll K=19;
ll n,m,k,c[K],a[K][N],p[N+K];
ll Cnt;
ll ans=1e18;
vector<ll> to[N];
struct Edge{
	ll u,v,w;
}e[M*2],E[M*2];
bool cmp(const Edge&x,const Edge&y){
	return x.w<y.w;
}
bool All0(){
	for(int i=1;i<=k;i++)
		if(c[i]!=0)
			return 0;
	return 1;
}
ll find(ll x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
void work(ll sum){
	ll res=sum;
	for(int i=1;i<=Cnt;i++) E[i]=e[i];
	sort(E+1,E+1+Cnt,cmp);
	for(int i=1;i<=n+k;i++) p[i]=i;
	for(int i=1;i<=Cnt;i++){
		ll ru=find(E[i].u),rv=find(E[i].v);
		if(ru!=rv){
			p[ru]=rv;
			res+=E[i].w;
		}
	}
	ans=min(ans,res);
	return;
}
void dfs(ll x,ll sum){
	if(x==k+1){
		work(sum);
		return;
	}
	for(int j=1;j<=n;j++){
		Cnt++;
		e[Cnt].u=x+n;
		e[Cnt].v=j;
		e[Cnt].w=a[x][j];
	} 
	dfs(x+1,sum+c[x]);
	Cnt-=n; 
	dfs(x+1,sum);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	Cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	if(All0()){
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++){
				Cnt++;
				e[Cnt].u=i+n;
				e[Cnt].v=j;
				e[Cnt].w=a[i][j];
			} 
		work(0);
	}
	else{
		dfs(1,0); 
	}
	cout<<ans<<endl;
	return 0;
}

