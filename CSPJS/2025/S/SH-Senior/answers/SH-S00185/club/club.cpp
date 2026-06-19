#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll n,ans,ec;
struct P{ll a[3];}p[N];
namespace t1{
	ll f[2][109][109];
	void sv(){
		for(ll x=0;x<=n/2;x++)for(ll y=0;y<=n/2;y++)
			f[0][x][y]=f[1][x][y]=0;
		for(ll i=1;i<=n;i++){
			bool d=i%2;
			for(ll x=0;x<=min(i,n/2);x++)
				for(ll y=max(0ll,i-x-n/2);y<=min(n/2,i-x);y++){
					if(x+y<i)f[d][x][y]=max(f[d][x][y],f[!d][x][y]+p[i].a[2]);
					if(x)f[d][x][y]=max(f[d][x][y],f[!d][x-1][y]+p[i].a[0]);
					if(y)f[d][x][y]=max(f[d][x][y],f[!d][x][y-1]+p[i].a[1]);
				}
		}
		for(ll x=0;x<=n/2;x++)for(ll y=n/2-x;y<=n/2;y++)
			ans=max(ans,f[0][x][y]);
		cout<<ans<<"\n";
	}
}
vector<ll>cl[3];
bool cmp1(const P&u,const P&v){return u.a[0]>v.a[0];}
ll df(ll u){
	ll d[3];
	for(int i=0;i<3;i++)d[i]=abs(p[u].a[ec]-p[u].a[i]);
	return d[0]+d[1]+d[2]-min(min(d[1],d[0]),d[2])-max(max(d[1],d[0]),d[2]);
}
bool cmp2(const ll&u,const ll&v){return df(u)<df(v);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll T;cin>>T;while(T--){
		cin>>n;ans=0;
		for(ll i=1;i<=n;i++)cin>>p[i].a[0]>>p[i].a[1]>>p[i].a[2];
		if(n<=200){t1::sv();continue;}
		bool a1=0,a2=0;
		for(ll i=1;i<=n;i++)a1|=p[i].a[1],a2|=p[i].a[2];
		if(!a1&&!a2){
			sort(p+1,p+1+n,cmp1);
			for(ll i=1;i<=n/2;i++)ans+=p[i].a[0];
			cout<<ans<<"\n";continue;
		}
		if(!a2){
			cl[0].clear();cl[1].clear();
			for(ll i=1;i<=n;i++){
				ll ch=(p[i].a[0]<p[i].a[1]);
				ans+=p[i].a[ch];cl[ch].push_back(i);
			}
			bool ec=(cl[1].size()>n/2);
			sort(cl[ec].begin(),cl[ec].end(),cmp2);
			for(ll i=0;i<(ll)cl[ec].size()-n/2;i++)
				ans-=p[cl[ec][i]].a[ec]-p[cl[ec][i]].a[!ec];
			cout<<ans<<"\n";continue;
		}
		cl[0].clear();cl[1].clear();cl[2].clear();
		for(ll i=1;i<=n;i++){
			ll ch=0;
			if(p[i].a[1]>p[i].a[ch])ch=1;
			if(p[i].a[2]>p[i].a[ch])ch=2;
			ans+=p[i].a[ch];cl[ch].push_back(i);
		}
		ec=(cl[1].size()>n/2);
		if(cl[2].size()>n/2)ec=2;
		sort(cl[ec].begin(),cl[ec].end(),cmp2);
		for(ll i=0;i<(ll)cl[ec].size()-n/2;i++)
			ans-=df(cl[ec][i]);
		cout<<ans<<"\n";
	}
	return 0;
}
