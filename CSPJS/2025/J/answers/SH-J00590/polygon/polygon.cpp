#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ma,ans;
int a[5010],b[5010];
void f(int x){
	if(x==n+1){
		int s=0;
		int mx=0;
		int vis=0;
		for(int i=1;i<=n;++i){
			if(b[i]){
				s+=a[i];
				mx=max(mx,a[i]);
				vis++;
			}
		}
		if(s>2*mx&&vis>=3){
			ans++;
			ans%=mod;
		}
		return;
	}
	b[x]=0;
	f(x+1);
	b[x]=1;
	f(x+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma==1){
		ans=1;
		for(int i=1;i<=n;++i){
			ans*=2;
			ans%=mod;
		}
		cout<<((ans-n*(n-1)/2-n-1)%mod+mod)%mod;
		return 0;
	}
	if(n<=20){
		f(1);
		cout<<ans;
	}
	return 0;
}
