#include <bits/stdc++.h>
using namespace std;

int a[500010], t[500010][25], s[500010][25], k[25], ans;

bool check(int l, int r){
	for (int i = 0; i <= 20; i++){
		int m = s[r][i]-s[l-1][i];
		if (m%2 != k[i]) return false;
	}
	return true;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, K;
	cin >> n >> K;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		int tmp = a[i], cur = 0;
		while (tmp > 0){
			t[i][cur] = tmp%2;
//			cout << t[i][cur] << " ";
			s[i][cur] = s[i-1][cur]+t[i][cur];
//			cout << s[i][cur] << " ";
			tmp /= 2;
			cur++;
		}
		for (int j = 0; j <= 20; j++){
			if (s[i][j]) continue;
			s[i][j] = s[i-1][j];
		}
//		cout << endl;
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j >= 0; j--){
//			cout << s[i][j] << " ";
//		}
//		cout << endl;
//	}
	int tmp = K, cnt = -1;
	while (tmp > 0){
		k[++cnt] = tmp%2;
//		cout << k[cnt] << endl;
		tmp /= 2;
	}
	int limit = n;
	for (int i = n; i >= 1; i--){
		for (int j = i; j <= limit; j++){
			if (check(i, j)){
				ans++;
//				cout << i << " " << j << endl;
				limit = i-1;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
