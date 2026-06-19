#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],sum,m;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n<=3){
		for (int i=1;i<=n;i++){
			sum+=a[i];
			m=max(m,a[i]);
		}
		if (sum>2*m) cout<<1;
		else cout<<0;
	}
	else{
		int ans=(n-2)%998244353;
		cout<<ans;
	}
	return 0;
}
