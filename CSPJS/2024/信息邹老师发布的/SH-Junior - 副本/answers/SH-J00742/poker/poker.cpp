#include <bits/stdc++.h>
using namespace std;
bool arr[105][105];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(int i = 1;i <= n;i++) {
		cin >> s;
		arr[(int)s[0]][(int)s[1]] = 1;
	}
	int cnt = 0;
	for(int i = 1;i <= 100;i++) {
		for(int j = 1;j <= 100;j++) {
			if(arr[i][j]) {
				cnt++;
			}
		}
	}
	cout << 52-cnt;
	return 0;
}
