#include<bits/stdc++.h>
using namespace std;
const long long N=5015;
const long long mod=998244353;
long long quickmi(long long a,long long b){
	long long ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
long long n;
long long f[10015];
long long read(){
	long long w=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret*w;
}
void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
long long a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	long long ans=0;
	f[0]=1;
	for(long long i=1;i<=n;i++){
		if(i>=3){
			long long tmp=0;
			for(long long j=0;j<=a[i];j++){
				tmp=(tmp+f[j])%mod; 
			}
			ans=(ans+quickmi(2,i-1)-tmp+mod)%mod;
		}
		for(long long j=10005;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
	}
	write(ans);
	return 0;
}
