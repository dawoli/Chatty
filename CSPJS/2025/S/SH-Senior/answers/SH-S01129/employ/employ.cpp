#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll ans,k,n,p[509],cnt;
string s;
bool all1(){
	for (int i=0;i<s.size();i++){
		if (s[i]!='1') return 0;
	}
	return 1;
}
void solve1(){
	ans=1;
	for (int i=1;i<=n;i++){
		ans=((k*i)%MOD+MOD)%MOD;
	}
	cout<<ans<<endl;
}
void solve18(){
	ans=1;
	for (int i=1;i<=k;i++){
		ans=((k*i)%MOD+MOD)%MOD;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]=='1') cnt++;
	}
	for (int i=1;i<=n;i++){
		cin>>p[i];
	}
	if (cnt<k) cout<<0<<endl;
	else if (all1()) solve1();
	else if (n<=18) solve18();
	return 0;
}
