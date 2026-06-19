#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans=0;
void f(int u,int sum,int mu,int cnt){
	if(u>n){
		if(sum>mu*2&&cnt>=3) ans++;
		ans%=998244353;
		return;
	}
	f(u+1,sum,mu,cnt);
	f(u+1,sum+a[u],max(mu,a[u]),cnt+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>20){
		long long ans=0;
		int k=n;
		while(k>=3){
			long long j=1,l=n-k;
			for(int i=1;i<=l;i++){
				j*=(n-i+1);
				j%=998244353;
			}
			for(int i=1;i<=l;i++) j/=i;
			ans+=j;
			ans%=998244353;
			k--;
		}
		cout<<ans;
	}
	else{
		f(1,0,0,0);
		cout<<ans;
	}
	return 0;
}
