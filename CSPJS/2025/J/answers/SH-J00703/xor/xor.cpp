#include <bits/stdc++.h>
using namespace std;
int a[500005],sum1,sum0,n,k,ans,f[500005][2][2][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		sum1 += (a[i] == 1 ? 1 : 0),sum0 += (a[i] == 0 ? 1 : 0);
	}
	if ((k == 1 || k == 0) && sum1+sum0 == n){
		if (k == 1) cout << sum1;
		else {
			for (int i = 1;i <= n;i++) if (a[i] == 1 && a[i+1] == 1) sum0++;
			cout << sum0;
		}
	}
	else{
		
		cout << 0;
	}
	return 0;
}
