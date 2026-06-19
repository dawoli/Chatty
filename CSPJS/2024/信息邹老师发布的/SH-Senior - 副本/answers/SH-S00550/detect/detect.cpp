#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,l,V,d[3010],v[3010],a[3010],p[3010],q[3010],vis[3010];
struct P{
	ll s,a[3010];
}s[3010];
bool cmp(const P &a,const P &b){
	return a.s>b.s;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(ll _=1;_<=t;++_){
		memset(s,0,sizeof(s));
		memset(vis,0,sizeof(vis));
		memset(q,0,sizeof(q));
		cin>>n>>m>>l>>V;
		for(ll i=1;i<=n;++i){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(ll i=1;i<=m;++i){
			cin>>p[i];
		}
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=m;++j){
				if(p[j]>d[i]&&V*V<v[i]*v[i]+2*a[i]*(p[j]-d[i])){
					q[i]=1;
					s[j].a[++s[j].s]=i;
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;++i){
			if(q[i]==1){
				ans++;
			}
		}
		cout<<ans<<" ";
		sort(s+1,s+m+1,cmp);
		ans=0;
		for(ll i=1;i<=m;++i){
			ll flag=1;
			for(ll j=1;j<=n;++j){
				if(vis[s[i].a[j]]==0){
					flag=0;
					vis[s[i].a[j]]=1;
				}
			}
			ans+=flag;
		}
		cout<<ans<<endl;;
	}
	
	return 0;
}
