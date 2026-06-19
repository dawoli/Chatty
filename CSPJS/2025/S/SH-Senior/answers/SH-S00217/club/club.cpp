#include <iostream>
#include <algorithm>
using namespace std;

int t,n,a[205][3],f[105][105][105],ans;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t-->0) {
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n/2;j++) {
				for (int k=1;k<=n/2;k++) {
					f[i][j][k]=max(f[i-1][j][k]+a[i+j+k][0],max(f[i][j-1][k]+a[i+j+k][1],f[i][j][k-1]+a[i+j+k][2]));
					ans=max(ans,f[i][j][k]);
				}
			}
		}
		cout << ans << endl;
	}
}
