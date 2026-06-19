#include<bits/stdc++.h>
#define N 200002
using namespace std;
typedef long long ll;
ll n,a[N],ans,t;
bool color[N];
void dfs(ll x){
	if(x>n){
		ll sum=0;
		for(ll i=2;i<=n;++i)
			for(ll j=i-1;j>=1;--j)
				if(color[i]==color[j]&&a[i]==a[j])sum+=a[i];
		ans=max(ans,sum);
		return;
	}
	color[x]=0;
	dfs(x+1);
	color[x]=1;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(ll p=1;p<=t;++p){
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;++i)cin>>a[i];
		if(n<=15){
			dfs(1);
			cout<<ans<<'\n';
		}else cout<<*max_element(a+1,a+n+1)<<'\n';
	}
	return 0;
}
