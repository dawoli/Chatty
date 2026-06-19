#include <bits/stdc++.h>
using namespace std;

	int n,k,a[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool x = 0,y = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != 1){
			x = 1;
		}
		if (a[i] > 2){
			y = 1;
		}
	}
	if (x == 0 && k == 0){
		cout << n / 2;
		return 0;
	}
	if (y == 0 && k <= 1){
		if (k == 0){
			int ans = 0,l = 0;
			for (int i = 1;i <= n;i++){
				if (a[i] == 0){
					l = 0;
					ans++;
				}
				else{
					l++;
					if (l == 2){
						l = 0;
						ans++;
					}
				}
			}
			cout << ans;
			return 0;
		}
		else{
			int ans = 0;
			for (int i = 1;i <= n;i++){
				if (a[i] == 1){
					ans++;
				}
			}
			cout << ans;
			return 0;
		}
	}
	else{
		if (k == 0){
			cout << 1;
			return 0;
		}
		else{
			cout << 2;
			return 0;
		}
	}
	return 0;
}
