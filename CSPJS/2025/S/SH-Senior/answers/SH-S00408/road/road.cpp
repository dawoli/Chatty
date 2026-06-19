#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,mn[15],fa[200009],c[15],g[15][100009];
bool v[2000009],fi;
struct Edge {
	ll x,y,w;
} e[2000009];
bool cmp(Edge a,Edge b) {
	return a.w<b.w;
}
int f(int x) {
	if(fa[x]==x) return x;
	return fa[x]=f(fa[x]);
}
void merge(int x,int y) {
	if(f(x)==f(y)) return ;
	fa[f(x)]=f(y);
	return ;
}
ll solve1() {
	ll ans=0;
	for(int i=1; i<=m; i++) {
		cin>>e[i].x>>e[i].y>>e[i].w;
	}
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=m; i++) {
		if(f(e[i].x)!=f(e[i].y)) {
			v[i]=true;
			merge(e[i].x,e[i].y);
			ans+=e[i].w;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	fi=true;
	if(k==0) {
		cout<<solve1();
		return 0;
	} else {
		for(int i=1; i<=m; i++) {
			cin>>e[i].x>>e[i].y>>e[i].w;
		}
		for(int i=1; i<=k; i++) {
			cin>>c[i];
			if(c[i]) fi=false;
			for(int j=1; j<=n; j++) cin>>g[i][j];
		}
		if(fi==true) {//A
			ll ans=0;
			int now=m+1;
			for(int i=1; i<=k; i++) {
				for(int j=1; j<=n; j++) {
					Edge tmp;
					tmp.x=n+i;
					tmp.y=j;
					tmp.w=g[i][j];
					e[now]=tmp;
					now++;
				}
			}
			sort(e+1,e+now,cmp);
			for(int i=1; i<now; i++) {
				if(f(e[i].x)!=f(e[i].y)) {
					v[i]=true;
					merge(e[i].x,e[i].y);
					ans+=e[i].w;
				}
			}
			cout<<ans;
		} else {
			ll ans=solve1();
			for(int i=1;i<=k;i++) {
				ll tmp=c[i];
				for(int j=1;j<=n;j++) {
					tmp+=g[i][j];
				}
				ans=min(ans,tmp);
			}
			cout<<ans;
		}
	}
	return 0;
}
