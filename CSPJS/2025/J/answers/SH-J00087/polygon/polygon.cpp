#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int n,c1;
ll a[5005],ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==1) c1++;
	}
	if(n<3){
		cout<<0<<"\n";
		return 0;
	}
	if(c1==n){
		if(n==3) ans=1;
		else if(n==4) ans=5;
		else if(n==5) ans=16;
		else{
			ll t=(n*(n-1)/2)%mod;
			ans=n+1+t;
			ans%=mod;
			int i;
			for(i=3;i<n/2;++i){
				t*=(n-i+1);
				t/=i;
				t%=mod;
				ans+=t*2;
				ans%=mod;
			}
			t*=(i+1);
			t/=i;
			if(n%2==0) ans+=t;
			else ans+=2*t;
			ans%=mod;
		}
	}
	else{
		sort(a+1,a+1+n);
		if(n==3&&a[1]+a[2]>a[3]) ans=1;
		
	}
	cout<<ans<<"\n";
	return 0;
}
