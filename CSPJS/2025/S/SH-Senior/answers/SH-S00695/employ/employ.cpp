#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;
#define int long long
int s[510], c[510], n, m;
bool is_selected[510];
int cnt;
vector<string> checked;
void solve(int i, deque<int>& selected) {
	if (i <= n) {
		for (int j = 1; j <= n; j++) {
			if (!is_selected[j]) {
				is_selected[j] = true;
				selected.push_back(s[j]);
				solve(i + 1, selected);
				selected.pop_back();
				is_selected[j] = false;
			}
		}
		return;
	}
	string str;
	for (int j = 0; j < selected.size(); j++) {
		str += selected[j] == 1 ? '1' : '0';
	}
	for (int j = 0; j < checked.size(); j++) {
		if (checked[j] == str) return;
	}
	checked.push_back(str);
	int employed = 0 ,failed = 0;
	for (int j = 1; j <= n && employed < m; j++) {
		if (failed >= c[j]) {
			failed++;
			continue;
		}
		if (selected[j - 1]) {
			employed++;
		} else {
			failed++;
		}
	}
	if (employed >= m) {
		cnt++;
		cnt %= 998244353ll;
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++) {
		char ch;
		scanf("%c", &ch);
		s[i] = (int)(ch == '1');
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	deque<int> selected;
	solve(1, selected);
	printf("%d", cnt);
	return 0;
}
