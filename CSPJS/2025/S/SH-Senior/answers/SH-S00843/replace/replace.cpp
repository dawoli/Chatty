#include <bits/stdc++.h>

using namespace std;

inline int read() {
	int res = 0, x = getchar();
	while (x < '0' || '9' < x) x = getchar();
	while ('0' <= x && x <= '9') res = res * 10 + x - '0', x = getchar();
	return res;
}

int n, q, hd1 = 1, hd2 = 2, cnt = 3, cnt2 = 0;
string s, t;

struct tire {
	int sn[26], hrnd, sumnd, fail, depth;
} tr[10000005];

void dfs(int x, int dep, const string &now) {
	tr[x].depth = dep;
	if (dep == now.size()) {
		tr[x].hrnd ++;
		return;
	}
	if (tr[x].sn[now[dep] - 'a'] == 0) tr[x].sn[now[dep] - 'a'] = cnt ++;
	dfs(tr[x].sn[now[dep] - 'a'], dep + 1, now);
}

int fnd(int x, const int &num) {
	if (x == hd1 || x == hd2) return x;
	if (tr[x].sn[num]) return tr[x].sn[num];
	return fnd(tr[x].fail, num);
}

vector<int> g[2][5000005];

struct node {
	int x, cnt;
};

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", &s, &t);
		dfs(hd1, 0, s);
		dfs(hd2, 0, t);
	}
	queue<int> q;
	q.push(hd1);
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < 26; ++i) {
			if (tr[top].sn[i]) {
				if (top == hd1) tr[tr[top].sn[i]].fail = hd1;
				else tr[tr[top].sn[i]].fail = fnd(tr[top].fail, i);
				g[0][tr[tr[top].sn[i]].fail].push_back(tr[top].sn[i]);
				q.push(tr[top].sn[i]);
			}
		}
	}
	q.push(hd2);
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < 26; ++i) {
			if (tr[top].sn[i]) {
				if (top == hd2) tr[tr[top].sn[i]].fail = hd2;
				else tr[tr[top].sn[i]].fail = fnd(tr[top].fail, i);
				g[1][tr[tr[top].sn[i]].fail].push_back(tr[top].sn[i]);
				q.push(tr[top].sn[i]);
			}
		}
	}
	queue<node> q2;
	q2.push({hd1, 0});
	while (!q2.empty()) {
		node top = q2.front();
		q2.pop();
		top.cnt += tr[x].hrnd;
		tr[x].sumnd = top.cnt;
		for (int i = 0; i < g[0][top].size(); ++i) {
			int v = g[0][top][i];
			q.push({v, top.cnt});
		}
	}
	q2.push({hd2, 0});
	while (!q2.empty()) {
		node top = q2.front();
		q2.pop();
		top.cnt += tr[x].hrnd;
		tr[x].sumnd = top.cnt;
		for (int i = 0; i < g[1][top].size(); ++i) {
			int v = g[1][top][i];
			q.push({v, top.cnt});
		}
	}
	while (q --) {
		long long ans = 0;
		scanf("%s %s", &s, &t);
		int ld = 0, rd = s.size() - 1, x = hd1, y = hd2;
		while (ld < s.size() && s[ld] == t[ld]) ld ++;
		while (rd >= 0 && s[rd] == t[rd]) rd --;
		bool flag;
		for (int i = 0; i < s.size(); ++i) {
			flag = false;
			x = fnd(x, s[i] - 'a');
			if (x == hd1) flag = true;
			y = fnd(y, t[i] - 'a');
			if (y == hd2) flag = true;
			if (flag) continue;
			if (i < rd) continue;
			if (tr[x].sumnd == 0 || tr[y].sumnd == 0) continue;
			int xx = x, yy = y;
			while (xx != hd1 && yy != hd2) {
				if (i - tr[xx].dep + 1 < ld) continue;
				ans += min(tr[xx].hrnd, tr[yy].hrnd);
				xx = tr[xx].fail, yy = tr[yy].fail;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
