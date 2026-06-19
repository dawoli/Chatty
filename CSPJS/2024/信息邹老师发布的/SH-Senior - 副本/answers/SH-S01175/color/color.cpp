#include <iostream>
using namespace std;
int T,n; 
int a[200005];
int maxx = -1;
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0;i < n;i++) {
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0;i < n;i++) {
			int cnt = 0;
			for(int j = i + 1;j < n;j++) {
				if(a[j] == a[i])
					cnt += 1;
			}
			ans = ans + cnt * a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
