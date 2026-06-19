#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, aa[200005], c[200005], d[20][200005], tow, les[20], T, x[4];
bool rem[200005];
char tmp;
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> aa[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> c[i];
	}
	tow = ceil(log2(n));
	for(int i = 1; i <= tow; ++i) {
		les[i] = (1 << tow) / (1 << i);
		for(int j = 1; j <= les[i]; ++j) {
			cin >> tmp;
			d[i][j] = tmp - '0';
		}
	}
	cin >> T;
	while(T--) {
		for(int i = 0; i <= 3; ++i) {
			cin >> x[i];
		}
		for(int i = 1; i <= n; ++i) {
			aa[i] ^= x[i % 4];
		}
		int fans = 0;
		for(int i = 1; i <= m; ++i) {
			int rtow = ceil(log2(c[i]));
			memset(rem, 0, sizeof rem);
			for(int j = 1; j <= (1 << rtow); ++j) {
				rem[j] = 1;
			}
			for(int j = rtow; j >= 1; --j) {
				for(int k = 1; k <= (1 << j) / 2; ++k) {
					int pos = d[rtow - j + 1][k];
					int maxxl = -1, minnl = 1e18, maxxr = -1, minnr = 1e18;
					for(int s = (k * 2 - 2) * (1 << (rtow - j)) + 1; s <= (k * 2 - 1) * (1 << (rtow - j)); ++s) {
						if(rem[s] == 0) continue;
						maxxl = max(maxxl, ((s <= c[i]) ? aa[s] : INT_MAX));
						minnl = min(minnl, ((s <= c[i]) ? aa[s] : 0));
					}
					for(int s = (k * 2 - 1) * (1 << (rtow - j)) + 1; s <= (k * 2) * (1 << (rtow - j)); ++s) {
						if(rem[s] == 0) continue;
						maxxr = max(maxxr, ((s <= c[i]) ? aa[s] : INT_MAX));
						minnr = min(minnr, ((s <= c[i]) ? aa[s] : 0));
					}
					if(pos == 0) {
						if(minnl >= rtow - j + 1) {
							for(int s = (k * 2 - 1) * (1 << (rtow - j)) + 1; s <= (k * 2) * (1 << (rtow - j)); ++s) {
								rem[s] = 0;
							}
						}
						if(maxxl < rtow - j + 1) {
							for(int s = (k * 2 - 2) * (1 << (rtow - j)) + 1; s <= (k * 2 - 1) * (1 << (rtow - j)); ++s) {
								rem[s] = 0;
							}
						}
						for(int s = (k * 2 - 2) * (1 << (rtow - j)) + 1; s <= (k * 2 - 1) * (1 << (rtow - j)); ++s) {
							if(((s <= c[i]) ? aa[s] : INT_MAX) < rtow - j + 1) {
								rem[s] = 0;
							}
						}
					}
					else {
						if(minnr >= rtow - j + 1) {
							for(int s = (k * 2 - 2) * (1 << (rtow - j)) + 1; s <= (k * 2 - 1) * (1 << (rtow - j)); ++s) {
								rem[s] = 0;
							}
						}
						if(maxxr < rtow - j + 1) {
							for(int s = (k * 2 - 1) * (1 << (rtow - j)) + 1; s <= (k * 2) * (1 << (rtow - j)); ++s) {
								rem[s] = 0;
							}
						}
						for(int s = (k * 2 - 1) * (1 << (rtow - j)) + 1; s <= (k * 2) * (1 << (rtow - j)); ++s) {
							if(((s <= c[i]) ? aa[s] : INT_MAX) < rtow - j + 1) {
								rem[s] = 0;
							}
						}
					}
				}
			} 
			int ans = 0;
			for(int j = 1; j <= (1 << rtow); ++j) {
				if(rem[j]) {
					ans += j;
				}
			}
			fans ^= (i * ans);
		}
		cout << fans << endl;
		for(int i = 1; i <= n; ++i) {
			aa[i] ^= x[i % 4];
		}
	}
	return 0;
} 
// ORZ COMPOSITE_FUNCTION
// ORZ JXY2011
// ORZ LITTLEACBG
// ORZ LIAOYANXU
// ORZ TIANTIAN2021

// EXPECTED SCORE : 100 + 100 + 65 + 40

// SOLUTION OF T1 : 
// Greedy. Let every monster with damage r attack every possible lower damage monsters.
// SOLUTION OF T2 :
// Using the formula of the acceleration and floor and ceil functions, the possible range of the placement of camera to detect the overspeed of each car can be calculated.
// The first question can be simply answered with prefix sum. The second question is to find a minimum usage of cameras to cover all the ranges.
// Sort them by the right end and greedy. Use lower_bound or upper_bound to find the right-most camera for each range to be covered.
// SOLUTION OF T3 (65pts) :
// The first 50 points are O(n^2), simple dp is okay. dp[i][j] represents the maximum value with the right-most red block is index i and the right-most blue block is index j.
// Special transfering only happens when |i-j|=1, whose occurences is O(n), so the dp is O(n^2).
// The other 15 points are O(n max(a)), just let i means the right-most block and j means the value of the right-most block with different color with i.
// SOLUTION OF T4 (40pts) :
// Simulate the eliminating process. Every unknown player's power can be calculated with both 0 and INT_MAX.
// Because the restriction of each round grows higher and higher every round, there will always be a possible power for each unknown player and a possible eliminating round.
// This algorithm is O(Tnm).
