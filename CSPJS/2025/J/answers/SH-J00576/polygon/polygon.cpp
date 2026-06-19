#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
const ll MOD=998244353;
ll n,a[N],f[N][N],s[N][N]; 
//CCF太强了 
//(看看能不能上迷惑代码那玩意儿) 
ll qmi(ll x,ll b,ll p){
	ll res=1;
	while(b){
		if(b&1) res=res*x%p;
		x=x*x%p;
		b>>=1;
	}
	return res;
} 
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int j=0;j<N;j++) s[0][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<N;j++){
			f[i][j]=f[i-1][j];
			if(j>=a[i])
				f[i][j]=(f[i][j]+f[i-1][j-a[i]])%MOD;
		}
		for(int j=0;j<N;j++)
			if(j) s[i][j]=(s[i][j-1]+f[i][j])%MOD; 
			else s[i][j]=f[i][j];
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=((ans+qmi(2,i-1,MOD))%MOD-s[i-1][a[i]])%MOD;
	cout<<(ans%MOD+MOD)%MOD<<endl;
	return 0;
}

