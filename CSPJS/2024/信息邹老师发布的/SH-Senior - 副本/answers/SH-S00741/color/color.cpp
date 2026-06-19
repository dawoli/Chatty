#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double ERR=0.00000001;
ll T;
ll n,ans;
ll a[100009];
ll tag[100009];
void dfs(ll id){
	if(id==n+1){
		ll res=0,last0=-1,last1=-1;
		for(ll i=1;i<=n;i++){
			if(tag[i]==0){
				if(last0==a[i]) res+=last0;
				last0=a[i];
			}
			else if(tag[i]==1){
				if(last1==a[i]) res+=last1;
				last1=a[i];
			}
		}
		ans=max(ans,res);
		return;
	}
	tag[id]=1;
	dfs(id+1);
	tag[id]=0;
	dfs(id+1);
}
void solvebf(){
	ans=0;
	dfs(1);
	printf("%lld\n",ans);
}
void solvedp(){
	
}
void solve(){
	
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=15) solvebf();
		else if(n<=2000) solvedp();
		else solve();
	}
	return 0;
}
