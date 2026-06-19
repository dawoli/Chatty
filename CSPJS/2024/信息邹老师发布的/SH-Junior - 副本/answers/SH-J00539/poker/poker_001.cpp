#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>

using namespace std;

int n;
string a[54];
int cnt = 0;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		bool flag = 0;
		for (int j = 1; j < i; j++) {
			if (a[i] == a[j]) {
				flag = 1;
				break;
			}
		}
		if (!flag) cnt++;
	}
	printf("%d", 52 - cnt);
	return 0;
}
