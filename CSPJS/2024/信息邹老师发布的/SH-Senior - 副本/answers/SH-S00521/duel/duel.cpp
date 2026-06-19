#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll c=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<1ll)+(c<<3ll)+(ch^48ll);
		ch=getchar();
	}
	return c*f;
}
const ll N=100009;
ll n,r[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++){
		r[i]=read();
	}
	sort(r+1,r+n+1);
	ll j=2,ans=n;
	for(ll i=1;i<=n;i++){
		while(j<=n&&r[i]>=r[j]) j++;
		if(j==n+1) break;
		ans--;
		j++;
	}
	printf("%lld\n",ans);
	return 0;
}

