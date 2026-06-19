#include <bits/stdc++.h>

using namespace std;

int N, ans;
vector<int> A;

void dfs(int d, int Sum, int Max, int Chosen) {
	if(Sum > Max + Max) {
		ans = (ans + 1) % 998244353;
	}
	for(int i = Chosen + 1; i <= N; i++) {
		dfs(d + 1, Sum + A[i], max(Max, A[i]), i);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> N;
	A = vector<int>(N + 1);
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	dfs(0, 0, 0, 0);
	cout << ans << '\n';
	
	return 0;
}
