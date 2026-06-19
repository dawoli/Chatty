#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
ll n,a[5005],maxx,sum,ans;
bool f;
stack<ll>s;
bool cmp(ll a,ll b){
	return a<b;
}
void dfs(ll w){
	if(w>n){
		if(!s.empty()&&sum>s.top()*2)	ans++;
		ans%=mod;
		return ;
	}
	dfs(w+1);
	s.push(w);
	sum+=a[w];
	dfs(w+1);
	sum-=a[w];
	s.pop();
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)	f=1;
	}
	if(!f){
		ll s=(n-1)*n,c=2;
		for(int i=3;i<=n;++i){
			s*=(n+1-i);
			c*=i;
			ans+=s/c;
			ans%=mod;
		}
		cout<<ans%mod; 
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	dfs(1);
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
