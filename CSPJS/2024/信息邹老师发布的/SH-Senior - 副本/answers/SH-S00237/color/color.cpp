#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
const ll M=1000009;
const ll INF=2e18;
ll T,n,a[N],m,mx,f[M],toAdd;
void read(ll &x){
	char c=getchar();
	while(!(c=='-'||c>='0'&&c<='9'))
	    c=getchar();
	bool t=0;
	if(c=='-')
	    t=1,c=getchar();
	x=0;
	while(c>='0'&&c<='9')
	    x=x*10+c-'0',c=getchar();
	if(t)x=-x;
}
void solve(){
	read(n);
	for(ll i=1;i<=n;i++)
	    read(a[i]);
	m=*max_element(a+1,a+n+1);
	for(ll i=1;i<=m;i++)
	    f[i]=-INF;
	f[0]=0;
	toAdd=0;
	mx=0;
	for(ll i=2;i<=n;i++){
		ll tmp=max(mx,f[a[i]]+toAdd+a[i]);
		if(a[i]==a[i-1]){
			toAdd+=a[i];
			mx+=a[i];
		}
		f[a[i-1]]=max(f[a[i-1]],tmp-toAdd);
		mx=max(mx,tmp);
	}
	printf("%lld\n",mx);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(T);
	while(T--)solve();
	return 0;
}
