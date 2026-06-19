#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long po(int i,int now,int m) {
	m++;
	i++;
	if(i >= n) {
		return 0;
	}
	now += a[i];
	if(m >= 3 && now > a[i] * 2) {
		return 1 + po(i,now - a[i - 1],m - 1) + po(i,now,m);
	}
	else {
		return po(i,now - a[i - 1],m - 1) + po(i,now,m);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	} 
	sort(a,a + n);
	if(n == 3) {
		int num = a[0] + a[1] + a[2];
		if(num > a[2] * 2) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		return 0;
	}
	long long ans = po(0,a[0],1);
	cout << ans % 998244353;
	return 0;
}
