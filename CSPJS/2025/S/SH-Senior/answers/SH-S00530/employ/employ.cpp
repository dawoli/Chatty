#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll f[20][300010];
ll n,m;
string s;
ll c[510],p[510];
ll pc(ll x){
	ll t=0;
	while(x){
		t+=x%2;
		x/=2;
	}
	return t;
}
void t(){
	f[0][0]=1; 
	for(ll i=1;i<p[n];++i){
		ll pcc=pc(i);
		for(ll j=0;j<=pcc;++j){
			for(ll k=1;k<=n;++k)
				if(i&(1<<(k-1))){
					ll lst=i-(1<<(k-1));
					if(s[pcc-1]=='1'&&c[k]>pcc-j&&j>0)		f[j][i]+=f[j-1][lst],f[j][i]%=MOD;
					else									f[j][i]+=f[j][lst],f[j][i]%=MOD;
				}
		}
	}
	cout<<f[m][p[n]-1]<<endl;
}
void u(){
	int v=n;
	for(ll i=1;i<=n;++i)
		if(!c[i])	v--;
	ll ret=1;
	for(ll i=1;i<=v;++i)	
		ret*=i,ret%=MOD;
	cout<<ret<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	p[0]=1;
	for(ll i=1;i<=20;++i)
		p[i]=p[i-1]*2;
	cin>>n>>m>>s;
	ll tt=1;
	for(int i=0;i<s.length();++i)
		tt&=(s[i]-'0');
	for(ll i=1;i<=n;++i)	cin>>c[i]; 
	if(n<=18)	t();
	if(tt)		u();
}
