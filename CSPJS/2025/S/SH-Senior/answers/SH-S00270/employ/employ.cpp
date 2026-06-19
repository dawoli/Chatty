#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s;
ll c[505];
ll a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (ll i=1;i<=n;i++){
		cin>>c[i];
	}
	for (ll i=1;i<=n;i++){	
		a[i]=i;
	}
	ll ans=0;
	do{
		ll failed_cnt=0;
		for (ll i=1;i<=n;i++){
			//cout<<a[i]<<'-';
			if (failed_cnt>=c[a[i]]) failed_cnt++;
			else if (s[i-1]=='0') failed_cnt++;
		}
		if (n-failed_cnt>=m) ans++;
	}while (next_permutation(a+1,a+n+1));
	cout<<ans%998244353<<endl;
	return 0;
}
