#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	int n,maxx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]); 
	}
	if(maxx=1&&n!=3){
		long long cnt=1,ans=1,mod=998244353,sum=0;
		
		for(int i=1;i<=n;i++){
			int nn=n;
			for(int j=1;j<=i;j++){
				cnt*=nn%mod;
				nn--;
			}
			for(int j=1;j<=i;j++){
				ans*=j%mod;
			}
			sum+=(cnt/ans)%mod;
			sum%=mod;
		}
		cout<<sum;
		return 0;
	}
	if(a[1]+a[2]+a[3]>maxx*2) cout<<1;
	else cout<<0;
	return 0;
} 
