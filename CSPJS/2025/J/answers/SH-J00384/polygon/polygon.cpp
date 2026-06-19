#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[5005];
const ll Mod=998244353;
ll pow_with_mod(int n,int m){
	ll ans=1;
	for (int i=1;i<=m;i++) {
		ans=(ans*n)%Mod;
	} 
	return ans%Mod;
}
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n ;
	int flag=1;
	for (int i=1;i<=n;i++) {
		cin >> num[i] ;
		if (num[i]!=1) flag=0;
	}
	sort(num+1,num+n+1) ;
	if (n<3) {
		cout << "0\n" ;
		return 0;
	}else if (n==3) {
		if (num[1]+num[2]>num[3]) cout << "1\n" ;
		else cout << "0\n";
		return 0;
	}else if (flag==1){
		ll ans1=pow_with_mod(2,n)-1;
		ll ans2=(n*(n-1)/2)%Mod;
		ll ans=(ans1-ans2-n+2*Mod)%Mod;
		cout << ans << endl ;
		return 0;
	}
	cout << "0\n" ;
	return 0;
}
