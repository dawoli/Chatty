#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010],s[5010];
long long C(int n,int m){
	if(m>n/2) m=n-m;
	long long s1=1,s2=1;
	for(int i=n;i>=n-m+1;i--) s1*=i;
	for(int i=1;i<=m;i++) s2*=i;
	return s1/s2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	bool f=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(f){
		long long cnt=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		for(int i=n;i>=1;i--){
			for(int j=1;j<=i;j++){
				if(s[i]-s[i-j]>a[i]*2){
					cnt++;
				}
			}
		}
		cout<<cnt%mod;
	}
	else{
		if(n>131) cout<<0;
		else{
			long long ans=0;
			for(int i=3;i<=n;i++){
				ans=(ans+C(n,i)%mod)%mod;
			}
			cout<<ans%mod;
		}
	}
	return 0;
}

