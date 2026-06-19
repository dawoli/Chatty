#include <iostream>
using namespace std;

int n,k,a[500005],ans;
bool v[500005];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	for (int l=1;l<=n;l++) {
		for (int i=1;i<=n-l+1;i++) {
			bool flag=1;
			int x=0;
			for (int f=i;f<=i+l-1;f++) {
				x=(x xor a[f]);
				if (v[f]==1) {
					flag=0;
					break;
				}
			}
			if (flag==1&&x==k) {
				ans++;
				for (int f=i;f<=i+l-1;f++) {
					v[f]=1;
				}
			}
		}
	}
	cout << ans;
}
