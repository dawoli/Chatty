#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 2e5+9;

ll T, n, a[N];

ll cl[N], ans=0;
ll cal(){
	ll c[2], res=0; c[0]=c[1]=-1;
	for(ll i=1; i<=n; i++){
		if(a[i]==c[cl[i]]) res+=a[i];
		c[cl[i]] = a[i];
	}
	return res;
}
void dfs(ll id){
	if(id>n){
		ans = max(ans, cal());
		return;
	}
	cl[id]=0;
	dfs(id+1);
	cl[id]=1;
	dfs(id+1);
} 
void solve15(){
	ans=0;
	dfs(1);
	cout<<ans<<endl;
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin>>T;
	for(; T>0; T--){
		cin>>n;
		for(ll i=1; i<=n; i++) cin>>a[i];
		
		if(n<=15) solve15();
	}
	
	return 0;
}
