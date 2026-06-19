#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
struct pos {
	int x,y;
	pos (int x=0, int y=0) {x=x; y=y;}
};
int T,n,k,q,x,l[N],r,c;
bool ans;
string S[N];
vector <pos> sta;
void dfs(int x,int y,int step,int r,int c) {
	if (step == r+1) return;
	for (int len = 2; (len <= k) && (y+len-1 < l[x]); len++) {
		string s0 = S[x].substr(y,y+len-1);
		if (step == r && s0[s0.size()-1] == c+'0') {
			ans = 1;
			printf("1\n");
			return;
		}
		char target = s0[s0.size()-1];
		for (int i = 1; (i <= n) && (i != x); i++) {
			bool flag = S[i].find(target) < S[i].size();
			if (flag) dfs(i,S[i].find(target),step+1,r,c);
		}
	}
	if (step == r && !ans) return;
}
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		bool tar = 0;
		scanf("%d%d%d",&n,&k,&q);
		for (int i = 1; i <= n; i++) {
			scanf("%d",&l[i]);
			bool fg = 0;
			for (int j = 1; j <= l[i]; j++) {
				scanf("%d",&x);
				if (x == 1 && !fg && j != l[i]) {
					sta.push_back(pos(i,j-1));
					fg = 1;
				}
				S[i] += x+'0';
			}
		}
		for (int a = 1; a <= q; a++) {
			ans = 0;
			scanf("%d%d",&r,&c);
			for (int i = 0; i < sta.size(); i++) {
				dfs(sta[i].x,sta[i].y,1,r,c);
				if (ans) {
					tar = 1;
					break;
				}
			}
			if (tar) break;
		}
		if (tar) continue;
		else printf("0\n");
	}
	return 0;
}
