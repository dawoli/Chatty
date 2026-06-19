#include <bits/stdc++.h>
#define N 100005
using namespace std;
long long n,M;
long long t[4*N],a[N],b[N];
void build(){
	for(M=1;M<=n+1;M<<=1);
	for(long long i=M+1;i<=M+n;i++) t[i]=a[i-M];
	for(long long i=M-1;i;i--) t[i]=max(t[i<<1],t[i<<1|1]);
}
/*void update(long long x,long long k){
	long long i=M+x;
	t[i]=k;
	for(i>>=1;i;i>>=1){
		t[i]=max(t[i<<1],t[i<<1|1]);
	}
}*/
long long ask(long long l,long long r){
	long long o=M+l-1,s=M+r+1;
	long long ret=0;
	while(o^s^1){
		if(~s&1){
			ret=max(ret,t[s^1]);
		}
		if(o&1){
			ret=max(ret,t[o^1]);
		}
		o>>=1,s>>=1;
	}
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		a[i]=a[i-1]+a[i];
		cout<<a[i]<<'=';
	}
	cout<<'\n';
	long long cnt=0;
	build();
	for(long long i=3;i<=n;i++){
		for(long long j=1;j<=n-i+1;j++){
			long long h=a[j+i-1]-a[j-1];
			long long d=ask(j,j+i-1);
			//cout<<h<<' '<<d<<'\n';
			//cout<<j+i-1<<'-'<<j-1<<'\n';
			if(h>2*d){
				cnt++;
				cnt%=998244353;
			}
		}
	}
	cout<<cnt;
	return 0;
}
