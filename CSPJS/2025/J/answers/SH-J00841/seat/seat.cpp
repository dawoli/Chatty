#include <bits/stdc++.h>
using namespace std;

int a[120];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,me,pos;
	cin >> n >> m;
	k = n*m;
	for (int i=1;i<=k;i++) {
		cin >> a[i];
	}
	me = a[1];
	sort(a+1,a+1+k);
	for (int i=1;i<=k;i++) {
		if (a[i] == me) {
			pos = k -i +1;
		}
	}
	int ans1 ,ans2;
//	cout << pos;
	double x,y,z;
	y = pos;
	z = n;
	x=  ceil(y/z);
	ans1 =x;
	int p,q;
	p = pos%n;

	if (p==0) {
		if (ans1 % 2==0) {
			p = 1;
		}else{
			p=n;
		}
	}else{
		if (ans1%2==0) {
			p = n - p +1;
			
		}
	}
	ans2 = p;
	cout << ans1 << ' ' << ans2;
	return 0;
}

