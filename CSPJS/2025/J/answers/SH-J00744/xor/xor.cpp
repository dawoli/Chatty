#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],cnt,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==1) cnt++;
	}
	if (k==1) cout<<cnt;
	else cout<<n-cnt;
	return 0;
}
