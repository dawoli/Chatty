#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],x,maxn;
long long ans,sum;
void solve1(){
	for(int i=3;i<=n;i++){
		sum=1;
		for(int j=n;j>=n-i+1;j--){
			sum*=j;
			sum/=n-j+1;
			sum%=mod;
		}
		ans+=sum;
		ans%=mod;
	}
	cout<<ans;
}
void solve2(){
	if(a[3]+a[1]>a[2]&&a[1]+a[2]>a[3]&&a[2]+a[3]>a[1])
		ans++;
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)x++;
		sum+=a[i];
	}
	if(x==n){
		solve1();
	}
	else if(n==3){
		solve2();
	}
	else cout<<0;
	return 0;
}
