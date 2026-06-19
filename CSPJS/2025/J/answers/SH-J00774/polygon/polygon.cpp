#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll N=5009;
ll n,a[N],ans;
bool vis[N];
inline ll read(){
	register ll x(0),f(1);
	register char c(getchar());
	while(c<'0'||c>'9'){if(c=='-') f=-1,c=getchar();}
	while(c>='0'&&c<='9'){ x=(x<<1)+(x<<3)+(c^'0'); c=getchar();}
	return x*f;
}
void dfs(ll num,ll pre,ll cnt,ll mx){
	if(num==n+1) return;
	if(num>=3){
		if(cnt>(2*mx)) ans++;
	}
	for(ll i=pre+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(num+1,i,cnt+a[i],max(mx,a[i]));
		vis[i]=0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
