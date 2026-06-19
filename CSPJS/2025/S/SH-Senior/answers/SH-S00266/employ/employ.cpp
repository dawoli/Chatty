#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[500];
string s;
long long qpow(int x){
	int ans=1,t=2;
	while(x){
		if(x&1)ans=(1ll*ans*t)%mod;
		t=(1ll*t*t)%mod;
		x>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ3.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i])cnt++;
	}
	if(cnt<m-1){
		cout <<0<<endl;return 0;
	}
	cout<<(qpow(cnt)-qpow(m-1)+mod)%mod<<endl;
	return 0;
}
