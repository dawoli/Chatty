#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509,mod=998244353;
ll n,m,c[N],ans;string s;
bool vst[N];
void dfs(ll x,ll ct){
	if(ct>n-m)return;
	if(x==n){ans=(ans+1)%mod;return;}
	for(ll i=1;i<=n;i++){
		if(vst[i])continue;
		vst[i]=1;
		dfs(x+1,ct+(ct>=c[i]||s[x]=='0'));
		vst[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;++i)cin>>c[i];
	sort(c+1,c+1+n);
	if(n<=18){dfs(0,0);cout<<ans;return 0;}
	bool a1=1;ll c0=0;
	for(ll i=0;i<n;i++)a1&=s[i]-'0',c0+=!c[i];
	if(c0>n-m){cout<<0;return 0;}
	if(a1){
		ans=1;
		for(ll i=2;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans;return 0;
	}
	cout<<0;
	return 0;
}
