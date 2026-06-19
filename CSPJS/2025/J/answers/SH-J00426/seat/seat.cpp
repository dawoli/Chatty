#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
ll n,m,cnt=0,a[N],b[N],wz,zw[N][N];
int cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) {
		cin >> a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++) {
		if(i%2!=0) {
			for(int j=1;j<=n;j++) {
				zw[j][i]=a[++cnt];
			}
		}
		else {
			for(int j=n;j>=1;j--) {
				zw[j][i]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(zw[i][j]==b[1]) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}

