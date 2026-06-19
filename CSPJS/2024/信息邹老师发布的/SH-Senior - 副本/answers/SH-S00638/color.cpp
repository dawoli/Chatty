// color

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int gA[N], n;

// BF1: O(2^n*n) 20pts
namespace BF1 {
	void Solve() {
		int mxn = (1LL << n), mx = 0;
		for (int i = 0; i < mxn; i++) {
			bool col[30];
			for (int j = 1; j <= n; j++)
				col[j] = ((i >> j - 1) & 1);
			
			int lst[2] = {-1, -1}, ans = 0;
			for (int j = 1; j <= n; j++) {
				ans += (gA[j] == lst[col[j]]) * gA[j];
				lst[col[j]] = gA[j];
			} mx = max(mx, ans);
		} cout << mx << endl;
	}
}

// BF2: O(n^2) 50pts
namespace BF2 {
	const int M = 5e3 + 10;
	int gB[M][M], gF[N];
	
	void Solve() {
		memset(gB, 0, sizeof(gB)); memset(gF, 0, sizeof(gF));
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++)
				gB[i][j] = gB[i][j - 1] + (gA[j - 1] == gA[j]) * gA[j];
		}
		
		for (int i = 1; i < n; i++)
			for (int j = 1; j < i; j++) // BUGBUG 转移细节错了 
				gF[i] = max(gF[i], gF[j] + gB[j + 1][i] + (gA[j] == gA[i + 1]) * gA[j]);
		
//		for (int i = 1; i <= n; i++)
//			cout << gF[i] << " ";
//		cout << endl;
		
		int ans = 0;
		for (int i = 1; i < n; i++) {
			// cout << i << ":calans:" << gF[i] << "+" << gB[i + 1][n] << endl;
			ans = max(ans, gF[i] + gB[i + 1][n]);
		}
		
		cout << ans << endl;
	}
}

// STD O(nlogn) 100pts
namespace STD {
	struct T {
		int mx, tg;
	}gT[N * 4];
	int gF[N], gSuf[N];
	
	void PushUp(int p) {
		gT[p].mx = max(gT[p * 2].mx, gT[p * 2 + 1].mx);
	}
	
	void AddTag(int p, int d) {
		gT[p].tg += d; gT[p].mx += d;
	}
	
	void PushDown(int p) {
		if (gT[p].tg) {
			AddTag(p * 2, gT[p].tg);
			AddTag(p * 2 + 1, gT[p].tg);
			gT[p].tg = 0;
		}
	}
	
	void Update(int p, int l, int r, int x, int y, int d) {
		if (x <= l && r <= y) {
			AddTag(p, d);
			return; 
		}
		
		PushDown(p);
		
		int mid = (l + r) / 2;
		if (x <= mid) Update(p * 2, l, mid, x, y, d);
		if (y > mid) Update(p * 2 + 1, mid + 1, r, x, y, d);
		
		PushUp(p);
	}
	
	int Query(int p, int l, int r, int x, int y) {
		if (x <= l && r <= y) return gT[p].mx;
		
		PushDown(p);
		
		int mid = (l + r) / 2, mx = 0;
		if (x <= mid) mx = max(mx, Query(p * 2, l, mid, x, y));
		if (y > mid) mx = max(mx, Query(p * 2 + 1, mid + 1, r, x, y));
		
		return mx;
	}
	
	void Solve() {
		memset(gF, 0, sizeof(gF));
		for (int i = n - 1; i >= 1; i--)
			gSuf[i] = gSuf[i + 1] + (gA[i] == gA[i + 1]) * gA[i];
		
		for (int i = 1; i < n; i++) {
			if (i > 2) Update(1, 1, n, 1, i - 2, (gA[i] == gA[i - 1]) * gA[i - 1]);
			for (int j = 1; j < i; j++) 
				gF[i] = max(gF[i], Query(1, 1, n, j, j) + (gA[j] == gA[i + 1]) * gA[i + 1]);
			
			Update(1, 1, n, i, i, gF[i]);
		}
		
//		for (int i = 1; i < n; i++)
//			cout << gF[i] << " ";
//		cout << endl;
//		
//		for (int i = 1; i < n; i++)
//			cout << gSuf[i] << " ";
//		cout << endl;
		
		int ans = 0;
		for (int i = 1; i < n; i++) ans = max(ans, gF[i] + gSuf[i]);
		
		cout << ans << endl;
		memset(gT, 0, sizeof(gT)); // BUGBUG 清空 
	}
}

signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	while (t--) {
		cin >> n;
		
		for (int i = 1; i <= n; i++)
			cin >> gA[i];
		
		if (n <= 15) BF1::Solve();
		else if (n <= 5000) BF2::Solve();
		else STD::Solve(); // BUGBUG 假了，没时间写完TAT 
	}
	
	return 0;
} 

/*
1#
1
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13

2#
1
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2 

3#
1
8
3 5 2 5 1 2 1 4
*/

/*
NOTE: 
Send it to: San Ba Bin Zang Guan Yi Tiao Long Fu Wu
Because lyx and dzh are in Beijing, I couldn`t solve this problem due to some seg-tree bugs. TAT
I guessed that this problem can be solved by a DP and dynamic-allocing points seg-tree.
I can just acclaim 50pts on this s***ting problem, What a pity! No way!!!!!
                                                                                 ---meitianyi 2024-10-26 18:27
*/
