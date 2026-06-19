#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll T,n,m,L,V,d[N],v[N],a[N],p[N],ans1,vis[N],ans2;
vector<ll> s[N],s2[N],tmp;
//set<ll>;
double eps=1e-6;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans1=0;
		memset(vis,0,sizeof(vis));
		ans2=0;
		tmp.clear();
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(ll i=0;i<n;i++){
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		}
		for(ll i=0;i<m;i++){
			scanf("%lld",&p[i]);
		}
		p[m]=L+1;
		//cout<<lower_bound(p,p+m+1,L+2)-p;
		for(ll i=0;i<n;i++){
			if(a[i]==0){
				if(v[i]>V){
					ll t=lower_bound(p,p+m+1,d[i])-p;
					if(t>=m)continue;
					s[t].push_back(i);
					s2[m].push_back(i);
					ans1++;
				}
			}
			if(a[i]>0){
				if(v[i]>V){
					ll t=lower_bound(p,p+m+1,d[i])-p;
					if(t>=m)continue;
					s[lower_bound(p,p+m+1,d[i])-p].push_back(i);
					s2[m].push_back(i);
					ans1++;
				}
				else{
					ll x=(V*V-v[i]*v[i])/2.0/a[i];
					ll t=lower_bound(p,p+m+1,d[i]+x+1)-p;
					if(t>=m)continue;
					s[t].push_back(i);
					s2[m].push_back(i);
					ans1++;
				}
			}
			if(a[i]<0){
				if(v[i]>V){
					ll x=(V*V-v[i]*v[i])/2.0/a[i]-eps;
					//cout<<x;
					ll t=lower_bound(p,p+m+1,d[i])-p;
					ll t2=upper_bound(p,p+m+1,d[i]+x)-p-1;
					//cout<<t<<t2;
					if(t2<0||t2<t){
//						cout<<x<<endl;
//						cout<<t<<endl;
//						cout<<t2<<endl;
						continue;
					}
					if(t>=m)continue;
					s[t].push_back(i);
					s2[t2].push_back(i);
					ans1++;
				}
			}
		}
		for(ll i=0;i<=m;i++){
			//cout<<s[i].size();
			for(ll it:s[i])tmp.push_back(it);
			for(ll it:s2[i]){
				if(vis[it])continue;
				ans2++;
				for(ll j:tmp)vis[j]=1;
				tmp.clear();
				break;
			}
		}
		printf("%lld %lld\n",ans1,m-ans2);
		for(ll i=0;i<=m;i++)s[i].clear();
		for(ll i=0;i<=m;i++)s2[i].clear();
	}
	return 0;
}
