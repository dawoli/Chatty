#include<bits/stdc++.h>
#define N 10002
#define K 12
#define M 1000002
#define INF 100000000000007
using namespace std;
typedef long long ll;
ll n,m,k,id[N+K],ans=INF,s[K],top,c[K],dis[N+K],p[N+K],tmp,tr;
vector<ll> to[N+K],w[N+K];
bool vst[N+K],choose[K];
struct node{
	ll u,d;
	bool operator<(const node&P)const{
		return d>P.d||d==P.d&&u>P.u;
	}
};
struct edge{
	ll u,v,w;
	bool operator<(const edge&P)const{
		return w<P.w;
	}
}e[M+N*K],e1[N*K];
ll root(ll u){
	return u==id[u]?u:id[u]=root(id[u]);
}
void dfs(ll x){
	if(x>k){
		ll r=tr,cnt=0;
		for(ll i=1;i<=n+k;++i)id[i]=i;
		if(r>=ans)return;
		/*
		memset(vst,0,sizeof(vst));
		fill(dis+1,dis+n+top+1,INF);
		dis[1]=0;
		fill(p+1,p+n+top+1,INF);
		p[1]=0;
		priority_queue<node> q;
		q.push(node({1,0}));
		while(!q.empty()){
			ll u=q.top().u,add=INF;
			q.pop();
			r+=p[u];
			vst[u]=1;
			for(ll i=0;i<to[u].size();++i){
				ll v=to[u][i],x=w[u][i];
				if(v>n&&!choose[v-n])continue;
				p[v]=min(p[v],x);
				if(vst[v]||dis[u]+x>=dis[v])continue;
				q.push(node({v,dis[u]+w[u][i]}));
				dis[v]=dis[u]+w[u][i];
				cout<<u<<"--->"<<v<<'\n';
			}
			if(r>=ans){
				cout<<"WHOOPS!\n";
				return;
			}
			--cnt;
			if(!cnt){
				ans=min(ans,r);
				return;
			}
		}
		*/
		
		ll cur=0,cur2=0;
		for(ll i=m+1;i<=tmp;++i)
			if(e[i].u>n&&choose[e[i].u-n])e1[++cur]=e[i];
		sort(e1+1,e1+cur+1);
		bool flag=0;
		for(ll i=1,j=1;i<=m;++i){
			while(j<=cur&&e1[j].w<=e[i].w){
				ll ru=root(e1[j].u),rv=root(e1[j].v);
				if(ru==rv){
					++j;
					continue;
				}
				id[ru]=rv;
				++cnt;
				r+=e1[j].w;
				if(cnt==n+top-1){
					flag=1;
					break;
				}
				++j;
			}
			if(flag)break;
			ll ru=root(e[i].u),rv=root(e[i].v);
			if(ru==rv)continue;
			id[ru]=rv;
			++cnt;
			r+=e[i].w;
			if(cnt==n+top-1)break;
		}
		ans=min(ans,r);
		return;
		
	}
	if(tr>=ans)return;
	dfs(x+1);
	s[++top]=x;
	choose[x]=1;
	tr+=c[x];
	dfs(x+1);
	--top;
	choose[x]=0;
	tr-=c[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;++i){
		ll u,v,x;
		scanf("%lld%lld%lld",&u,&v,&x);
		/*
		to[u].push_back(v);
		to[v].push_back(u);
		w[u].push_back(x);
		w[v].push_back(x);
		*/
		e[i]=edge({u,v,x});
	}
	for(ll i=1;i<=n;++i)id[i]=i;
	tmp=m;
	sort(e+1,e+m+1);
	for(ll i=1;i<=m;++i)e1[i]=e[i];
	for(ll i=1;i<=k;++i){
		scanf("%lld",c+i);
		for(ll j=1;j<=n;++j){
			ll q;
			scanf("%lld",&q);
			/*
			to[i+n].push_back(j);
			to[j].push_back(i+n);
			to[i+n].push_back(q);
			to[j].push_back(q);
			*/
			e[++tmp]=edge({i+n,j,q});
		}
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
