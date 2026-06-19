#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 500001;
int arr[maxn] = {0}, arrX[maxn] = {0}, arrY[maxn] = {0}, dp_arr[maxn] = {0};
int l = 1;

int sum (int start, int end) {
	int num = arr[start];
	
	for (int i = start + 1; i <= end; i++) {
		num = (num ^ arr[i]);
	}
	
	return num;
}

void dp (int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			
		}
	}
}

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (sum(i, j) == k) {
				arrX[l] = i;
				arrY[l] = j;
				l++;
			}
		}
	}
	
	cout << l - 1;
	//cout << dp_arr[n][n];
	return 0;
}
