#include <iostream>
#include <queue>
#include <vector>
#include <cstring> 
using namespace std;
struct stu {int id/*走了几步*/, x/*点*/, last/*上个接龙的人*/;};
struct stu2 {int v/*点*/, blon/*使该边联通的入*/;};
queue<stu> q;
vector<stu2> edge[10001];
bool f[101][10001];
int T, tot, n, k, Q, L, s[200001], r[100001], c[100001];
void solve2(int Q) {
	for (int i = 1; i <= n; i++) {
		scanf("%d", &L);
		for (int j = 1; j <= L; j++) scanf("%d", &s[j]);
	}
	for (int i = 1; i <= Q; i++) {
		scanf("%d%d", &r[i], &c[i]);
		cout << 0 << endl;
	}
}
void solve() {
	for (int i = 1; i <= 10001; i++) edge[i].clear();
	while (!q.empty()) q.pop(); 
	memset(f, 0, sizeof(f));
	int maxn = 0;
	scanf("%d%d%d", &n, &k, &Q);
	if (n > 10000) {
		solve2(Q);
		return;
	} 
	for (int i = 1; i <= n; i++) {
		scanf("%d", &L);
		for (int j = 1; j <= L; j++) {
			scanf("%d", &s[j]);
			for (int l = j - 1; l >= 1 && j - l + 1 <= k; l--) edge[s[l]].push_back({s[j], i});
		}
	}
	for (int i = 1; i <= Q; i++) {
		scanf("%d%d", &r[i], &c[i]);
		maxn = max(maxn, r[i]);
	}
	f[0][1] = 1;
	q.push({0, 1, 0});
	while (!q.empty()) {
	 	int node = q.front().x, id = q.front().id, last = q.front().last;
	 	//cout << node << " " << id << " " << last << endl; 
 		q.pop();
	 	if (id > maxn) break;
 		for (int i = 0; i < edge[node].size(); i++) {
 			int v = edge[node][i].v, blon = edge[node][i].blon;
 			if (blon == last) continue;
 			//printf("来自%d的%d到%d使得f[%d][%d]为1，往队列中加入{%d, %d, %d}\n", blon, node, v, id + 1, v, id + 1, v, blon);
 			f[id + 1][v] = 1, q.push({id + 1, v, blon});
		}
	}
	for (int i = 1; i <= Q; i++) cout << f[r[i]][c[i]] << endl;
}
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout); 
	scanf("%d", &T);
	tot = T;
	while (tot--) solve();
	return 0;
}
/*
尝试更快的连边方式：
能抵达s[j]的点仅比能抵达s[j - 1]的点少一个s[j - k]多一个s[j - 1];
*/
/*求在r次接龙后最后一个元素为c的可行性
接龙：选择一个s的子串L 其长度为2~k。 
L的开头必须为接龙序列的最后一个元素 
第一个元素必须为1

O1处理询问
从1开始移动i步，可以抵达者f[i][c] |= f[i - 1][可以到c的点];
连边->dp->解决询问 
 

预处理连边:




DP代码:



询问代码：cout << f[r][c] << endl; 




对于所有Σl<=2000的，可以使用
for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= l[i]; j++) {
		for (int l = 1; l < k; l++) { 
			if (!box[i][s[i][j + l]]) box[i][s[i][j + l]] = 1, edge[i][s[i][j]].push_back(s[i][j + l]);
		}
	}
}*/
