#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[5010],ans,maxx=0,cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(n==3){
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
				cnt+=a[i];
			}
			if(cnt>maxx*2){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
	}
	else{
		for(int i=n-2;i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod;
	}
	return 0;
}

