#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10109,M=1100009;
ll n,nn,nnn,m,k,ans=1e18,fa[N];
struct E{ll u,v,w;};
struct P{ll cs,a[N];}p[15];
vector<E>e,ed;
bool cmp(const E&x,const E&y){return x.w<y.w;}
ll fd(ll x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;nn=n;
	for(ll i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;e.push_back({u,v,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>p[i].cs;
		for(ll j=1;j<=n;j++)cin>>p[i].a[j];
		if(p[i].cs)continue;
		nn++;
		for(ll j=1;j<=n;j++)e.push_back({nn,j,p[i].a[j]});
		i--;k--;
	}
	sort(e.begin(),e.end(),cmp);
	for(ll zy=0;zy<(1<<k);zy++){
		ll rs=0;nnn=nn;ed.clear();
		for(ll i=1;i<=k;i++)if(zy&(1<<(i-1))){
			rs+=p[i].cs;nnn++;
			for(ll j=1;j<=n;j++)ed.push_back({nnn,j,p[i].a[j]});
		}
		sort(ed.begin(),ed.end(),cmp);
		for(ll i=1;i<=nnn;i++)fa[i]=i;
		for(ll i=nnn,x=0,y=0,ww,wd;i>1;i--){
			while(x<e.size()&&fd(e[x].u)==fd(e[x].v))x++;
			while(y<ed.size()&&fd(ed[y].u)==fd(ed[y].v))y++;
			ww=wd=1e18;
			if(x<e.size())ww=e[x].w;
			if(y<ed.size())wd=ed[y].w;
			if(ww<wd){
				ll uu=fd(e[x].u),vv=fd(e[x].v);
				fa[uu]=vv;rs+=ww;x++;
			}else{
				ll uu=fd(ed[y].u),vv=fd(ed[y].v);
				fa[uu]=vv;rs+=wd;y++;
			}
			if(rs>=ans)break;
		}
		ans=min(ans,rs);
	}
	cout<<ans;
	return 0;
}
