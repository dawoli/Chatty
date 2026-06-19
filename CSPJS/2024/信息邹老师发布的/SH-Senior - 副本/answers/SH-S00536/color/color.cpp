#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;
ll n,a[N],ans;
ll p[N];
vector<ll> Red,Blue;
ll work(){
	ll sum=0;
	Red.clear();
	Blue.clear();
	for(int i=1;i<=n;i++)
		if(p[i]) Red.push_back(i);
		else Blue.push_back(i);
	for(int i=1;i<Red.size();i++)
		if(a[Red[i]]==a[Red[i-1]])
			sum+=a[Red[i]];
	for(int i=1;i<Blue.size();i++)
		if(a[Blue[i]]==a[Blue[i-1]])
			sum+=a[Blue[i]];
	ans=max(ans,sum);
}
void dfs(ll x){
	if(x==n+1){
		work();
		return;
	}
	p[x]=0;
	dfs(x+1);
	p[x]=1;
	dfs(x+1);
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
