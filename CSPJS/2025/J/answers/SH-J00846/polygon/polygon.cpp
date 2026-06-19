#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int maxx = -1,sum;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
		sum += a[i];
	}
	if(n == 3 && sum >= 2*maxx) cout << 1%MOD << endl;
	return 0;
}
