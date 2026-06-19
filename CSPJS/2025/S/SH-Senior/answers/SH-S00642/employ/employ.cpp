#include<bits/stdc++.h>
#define MOD 998244353
#define N 502
using namespace std;
typedef long long ll;
ll n,m,ans,c[N],p[N];
string s;
bool A=1,v[N];
void dfs(ll k){
	if(k>n){
		ll cnt=0;
		for(ll i=1;i<=n;++i){
			if(n-cnt<m)return;
			if(cnt>=c[p[i]]||s[i-1]=='0')++cnt;
		}
		if(n-cnt>=m)++ans;
		return;
	}
	for(ll i=1;i<=n;++i){
		if(v[i])continue;
		v[i]=1;
		p[k]=i;
		dfs(k+1);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=0;i<n;++i)
		if(s[i]=='0'){
			A=0;
			break;
		}
	for(ll i=1;i<=n;++i)cin>>c[i];
	if(A||m==1){
		ans=1;
		for(ll i=1;i<=n;++i)ans=ans*i%MOD;
		cout<<ans;
	}else{
		dfs(1);
		cout<<ans%MOD;
	}
	return 0;
}
