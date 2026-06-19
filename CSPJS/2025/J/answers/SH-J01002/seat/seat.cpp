#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int N = 110;
int grade[N], n, m, a1;
bool f[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int paiming = 0;
	cin>>n>>m;
	for (int i = 1; i <= m*n; i ++) {
		cin>>grade[i];
		f[grade[i]] = 1;
	}
	a1 = grade[1];
	for (int i = 100; i >= 1; i --) {
		if (f[i]) paiming++;
		if (i==a1) {
			break;
		}
	}
	int lie = (paiming-1)/n+1, hang = (paiming-1)%n+1;
	if (lie%2==0) {
		cout<<lie<<" "<<n-hang+1;
		return 0;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
