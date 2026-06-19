#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll T,n,a[N][3],ans;
multiset<ll> s[3];
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=((bool)(c^'-')<<1)-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
void calc(ll type){
	ll cnt=s[type].size()-(n/2);
	for(ll i=1;i<=cnt;++i)
		ans-=(*s[type].begin()),s[type].erase(s[type].begin());
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();ans=0;
		s[0].clear();
		s[1].clear();
		s[2].clear();
		for(ll i=1;i<=n;++i){
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();//
			ll maId=0,sun=0;
			for(ll j=1;j<=2;++j)
				if(a[i][j]>a[i][maId]) maId=j;
			ans+=a[i][maId];
			sun=max(a[i][(maId+1)%3],a[i][(maId+2)%3])-a[i][maId];
			s[maId].insert(-sun);
//			cout<<i<<":"<<sun<<"\n";
		}
		if(s[0].size()>n/2) calc(0);
		if(s[1].size()>n/2) calc(1);
		if(s[2].size()>n/2) calc(2);
		cout<<ans<<"\n";
	}
	return 0;
}
