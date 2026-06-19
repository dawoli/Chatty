#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000001;
int arr[maxn] = {0};

bool isNum (int num) {
	if (num >= 0 && num <= 9) {
		return true;
	} else {
		return false;
	}
}

bool compare (int a, int b) {
	return a > b;
}

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	int res = 0;
	int l = 1;
	for (int i = 0; i < s.size(); i++) {
		if (isNum(s[i] - '0')) {
			arr[l] = s[i] - '0';
			l++;
		}
	}
	
	sort (arr + 1, arr + l + 1, compare);
	
	for (int i = 1; i <= l - 1; i++) {
		cout << arr[i];
	}
	
	return 0;
}
