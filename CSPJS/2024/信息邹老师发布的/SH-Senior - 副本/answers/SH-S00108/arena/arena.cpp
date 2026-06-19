#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int n, m, k, K, T, a[N], c[N], ai[N];
string rad[N];
int nor(int a, int b){
	int a2[N], b2[N], ans[N], an = 1, bn = 1, key = 0;
	while (a != 0){
		a2[an++] = a / 2;
		a %= 2;
	}
	a2[an] = 0;
	while (b != 0){
		b2[bn++] = b / 2;
		b %= 2;
	}
	b2[bn] = 0;
	for (int i = max(an, bn); i >= 1; i--){
		if (a2[i] == 1 || b2[i] == 1){
			ans[i] = 1;
		}else{
			ans[i] = 0;
		}
	}
	for (int i = max(an, bn); i >= 1; i--){
		key += ans[i] * pow(2, max(an, bn) - i);
	}
	return key;
}
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++){
		cin >> c[i];
	}
	while (pow(2, K) < n){
		K++;
	}
	for (int i = 1; i <= K; i++){
		cin >> rad[i];
	}
	cin >> T;
	while (T--){
		int x[4], ans[m], an = 1, key = 0;
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for (int i = 1; i <= n; i++){
			ai[i] = nor(a[i], x[i % 4]);
		}
		for (int i = 1; i <= m; i++){
			int cnt = 0;
			while (pow(2, k) < c[i]){
				k++;
			}
			int maxid = 1;
			for (int j = 2; j <= n; j++){
				if (ai[maxid] < ai[j]){
					maxid = j;
				}
			}
			if (k > c[i]){
				cnt += 2;
			}else{
				cnt++;
			}
			ans[an++] = cnt;
		}
		for (int i = 1; i <= m; i++){
			key = nor(key, (i * ans[i]));
		}
		cout << key << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
