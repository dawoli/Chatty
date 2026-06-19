#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,c[19];
ll a[19][100009];
bool isTypeA=1;
struct Edge{
	ll u,v,w;
}eds[1000009];
namespace TypeA{
	Edge seds[1100009];
	int cnt,fa[10019];
	ll ans;
	bool cmp(const Edge &a,const Edge &b){
		return a.w<b.w; 
	}
	int fndfa(int x){
		if(fa[x]==x) return x;
		else return fa[x]=fndfa(fa[x]);
	}
	void solve(){
		for(int i=1;i<=m;i++){
			seds[i]=eds[i];
		}
		cnt=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				seds[++cnt]=(Edge){j,i+n,a[i][j]};
			}
		}
		sort(seds+1,seds+cnt+1,cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=cnt;i++){
			int u=seds[i].u,v=seds[i].v;
			if(fndfa(u)==fndfa(v)) continue;
			ans+=seds[i].w;
			fa[fa[u]]=v;
		}
		cout<<ans<<endl;
	}
}//provides AC on 12 test cases aka. 48pts
namespace wtf{
	Edge seds[1000009],neds[100009];
	int cnt,fa[10019];
	ll ans=1e18,nans;
	bool cmp(const Edge &a,const Edge &b){
		return a.w<b.w; 
	}
	int fndfa(int x){
		if(fa[x]==x) return x;
		else return fa[x]=fndfa(fa[x]);
	}
	void solve(){
		for(int i=1;i<=m;i++){
			seds[i]=eds[i];
		}
		sort(seds+1,seds+m+1,cmp);
		
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				neds[++cnt]=(Edge){i+n,j,a[i][j]};
			}
		}
		sort(neds+1,neds+cnt+1,cmp);
		for(int now=0;now<(1<<k);now++){
			nans=0;
			int chunks=n;
			for(int i=1;i<=k;i++){
				if((now>>(i-1))&1){
					nans+=c[i];
					chunks++;
				}
			}
			int l=1,r=1;
			for(int i=1;i<=n+k;i++) fa[i]=i;
			while(chunks>1){
				Edge enow=(Edge){0,0,0};
				while(!((now>>(neds[r].u-n-1))&1)&&r<=cnt) r++;
				if(l>m){
					enow=neds[r++];
				}
				else if(r>cnt){
					enow=seds[l++];
				}
				else{
					if(cmp(seds[l],neds[r])) enow=seds[l++];
					else enow=neds[r++];
				}
				if(fndfa(enow.u)==fndfa(enow.v)) continue;
				nans+=enow.w;
				fa[fa[enow.u]]=enow.v;
				chunks--;
			}
			ans=min(nans,ans);
		}
		cout<<ans<<endl;
	}
}//provides AC on ~3 test cases aka. ~12pts
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>eds[i].u>>eds[i].v>>eds[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) isTypeA=0;
		bool has0=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(!a[i][j]) has0=1;
		}
		if(!has0) isTypeA=0;
	}
	if(isTypeA) TypeA::solve();
	else wtf::solve();
	return 0;
}
