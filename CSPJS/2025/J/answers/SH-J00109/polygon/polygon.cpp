#include<bits/stdc++.h>
using namespace std;

long long n;

int main(){
	//²»ÄÜÉ¾£¡£¡£¡£¡£¡£¡ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int maxx=max(max(a,b),c);
		if(a+b+c>maxx*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	long long cnt=1;
	for(int i=1;i<=n;i++){
		cnt*=2;
		cnt%=998244353;
	}
	cnt=(cnt-1+998244353)%998244353;
	cnt=(cnt-n+998244353)%998244353;
	cnt=(cnt-n*(n-1)/2+998244353)%998244353;
	cout<<cnt;
	return 0;
}

