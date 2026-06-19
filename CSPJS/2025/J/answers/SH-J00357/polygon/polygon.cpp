#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1001;
int arr[maxn] = {0};

const ll modNum = 998244353;

bool flagArr[maxn];
bool isPolygon (int n) {
	int maxLength = 0, lengthSum = 0, trueNum = 0;
	for (int i = 1; i <= n; i++) {
		if (flagArr[i]) {
			trueNum++;
			maxLength = max(maxLength, arr[i]);
			lengthSum += arr[i];
		}
	}
	
	return (trueNum >= 3) && (lengthSum > (maxLength * 2));
}

int sum = 0;
void dfs (int num, int n) {
	if (num == 0) {
		return ;
	}
	
	flagArr[num] = 1;
	dfs(num - 1, n);
	if (isPolygon(n)) {
		sum++;
	}
	
	
	flagArr[num] = 0;
	dfs(num - 1, n);
//	if (isPolygon(n)) {
//		sum++;
//	}
	
}

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	dfs(n, n);
	
	cout << sum;
	return 0;
}
