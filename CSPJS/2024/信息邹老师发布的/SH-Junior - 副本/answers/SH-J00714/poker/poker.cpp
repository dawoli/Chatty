#include<iostream>
#include<cstring>
using namespace std;

int n, ans = 0;
string ss, s[100];

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		ans++;
		for (int j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				ans--;
				break;
			}
		}
	}
	cout << 52 - ans;
	
	return 0;
} 
