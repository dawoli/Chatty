#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
using namespace std;

typedef long double db;
typedef pair<int, int> PII;
void file_IO(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
}

const int N = 1e5 + 10;
int n, cnt, r[N];

signed main(){
	file_IO();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n, cnt = n;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	sort(r + 1, r + n + 1);
	for (int i = 1, j = 2; i <= n; i++){
		while (j < n && r[j] <= r[i])
			j++;
		if (i != j && j != n + 1 && r[j] > r[i])
			cnt--, j++;
	}
	cout << cnt << endl;
	return 0;
}
//liyelin AK IOI
