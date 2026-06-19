#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,m,c[505],s[505];
string str;
ll b[505],v[505],ans;
bool A1(){
	for(ll i=1;i<=n;i++){
		if(!s[i]){
			return false;
		}
	}
	return true;
}
ll f(ll x){
	ll ans=1;
	for(ll i=1;i<=x;i++){
		ans=ans*i%MOD;
		//cout<<ans<<endl;
	}
	return ans;
}
void dfs(ll x){
	if(x==n+1){
		ll cntg=0,cnt=0;
		for(ll i=1;i<=n;i++){
			if(c[b[i]]>cntg&&s[i]){
				cnt++;
			}
			else{
				cntg++;
			}
		}
		(ans+=(cnt>=m))%=MOD;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(v[i]){
			continue;
		}
		b[x]=i;
		v[i]=1;
		dfs(x+1);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	str=" "+str;
	for(ll i=1;i<=n;i++){
		s[i]=str[i]-'0';
		cin>>c[i];
	}
	if(A1()){
		cout<<f(n);
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

