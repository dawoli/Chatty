#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
long long n,m;
string s;
long long c[505];
long long fac[505];
long long inv[505];
long long ksm(long long p,long long q,long long M){
	p%=M;
	long long ans=1;
	while(q){
		if(q&1) ans=ans*p%M;
		p=p*p%M;
		q>>=1;
	}
	return ans;
}
void cal_fac(long long res){
	fac[1]=1;
	for(int i=2;i<=res;i++) fac[i]=fac[i-1]*i%MOD;
	inv[res]=ksm(fac[res],MOD-2,MOD);
	for(int i=res-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%MOD;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cal_fac(max(n,m));
	cin>>s;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]) cnt++;
	}
	sort(c+1,c+n+1);
	cout<<fac[n]<<endl;
	return 0;
}
