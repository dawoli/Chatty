#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n;
const long long N=5e5+5;
long long a[N];
const long long mod=998244353;
long long sum=0;
long long maxx=0;
long long ans=0;
long long cnt=0;
bool flag=1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		long long pro=1;
		for(long long i=1;i<=n;i++){
			pro*=2;
			pro%=mod;
		}
		int c2=n*(n-1)/2%mod;
		cout<<pro-c2-n-1;
	}
	else if(n<=20){
		for(long long i=0;i<1<<n;i++){
			maxx=0;
			sum=0;
			for(long long j=0;j<n;j++){
				if((i>>j)&1==1){
					maxx=max(maxx,a[j+1]);
					sum+=a[j+1];
					cnt++;
				}
			}
			if(sum>2*maxx && cnt>=3) ans++;
		}
		cout<<ans;
	}
	else{
		for(long long i=0;i<1<<n;i++){
			maxx=0;
			sum=0;
			for(long long j=0;j<n;j++){
				if((i>>j)&1==1){
					maxx=max(maxx,a[j+1]);
					sum+=a[j+1];
					cnt++;
				}
			}
			if(sum>2*maxx && cnt>=3) ans++;
		}
		cout<<ans;
	}
	return 0;
}
