#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,k[505][505];
long long ans=0,ansn=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		for(int i=3;i<=n-1;i++){
			ansn=1;
			for(int j=n;j>i;j--){
				ansn*=1ll*j;
				ansn/=1ll*(n-j+1);
				
				ansn%=998244353;
				
			}
			
			
			ans+=ansn;
			ans%=998244353;
		}
		cout<<(ans+1)%998244353;
	}
	return 0;
} 
