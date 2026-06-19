#include<bits/stdc++.h>
using namespace std;
const long long N=5001;
long long a[N],b[N][N];
const long long mod=998244353;
long long qpow(long long a,long long b){
	long long p=1;
	while(b){
		if(b&1) p*=a;
		a*=a;
		p%=mod;
		a%=mod;
		b>>=1;
	}
	return p;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,s=0;
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i],s=max(s,a[i]);
	sort(a+1,a+n+1);
	for(long long i=0;i<=s;i++) b[i][1]=1;
	for(long long i=0;i<=s;i++) for(long long j=2;j<=n;j++) b[i][j]=b[i][j-1]+(i>=a[j-1]?b[i-a[j-1]][j-1]:0),b[i][j]%=mod;
	long long sum=0;
	for(long long i=1;i<=n;i++) sum+=qpow(2,i-1)-b[a[i]][i],sum%=mod;
	cout<<(sum+mod)%mod<<endl;
	return 0;
}
