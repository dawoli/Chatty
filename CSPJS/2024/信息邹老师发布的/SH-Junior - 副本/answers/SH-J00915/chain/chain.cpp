#include <bits/stdc++.h>
using namespace std;
int T, n, K, q, s[105][200005], p[105][200005], pp[105][200005], beg[100005], ed[100005], l[100005], num[200005], curp, vis[200005];
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	while(T--) {
		memset(s, 0, sizeof s);
		memset(p, 0, sizeof p);
		memset(pp, 0, sizeof pp);
		memset(beg, 0, sizeof beg);
		memset(ed, 0, sizeof ed);
		curp = 0;
		cin >> n >> K >> q;
		--K;
		for(int i = 1; i <= n; ++i) {
			cin >> l[i];
			for(int j = 1, tmp = 0; j <= l[i]; ++j) {
				++curp;
				cin >> num[curp];
			}
			ed[i] = curp;
			beg[i] = curp - l[i] + 1;
		}
		for(int j = 1; j <= curp; ++j) {
			if(num[j] == 1) {
				s[0][j] = 1;
				++p[0][1];
			}
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = beg[i]; j <= ed[i]; ++j) {
				vis[num[j]] += (s[0][j] == 1);
			}
			for(int j = beg[i], su = 0, ss = 0; j <= ed[i]; ++j) {
				pp[0][j] = su;
				if(j - beg[i] >= K) {
					su -= p[0][num[j - K]];
					ss -= vis[num[j - K]];
				}
				su += p[0][num[j]];
				ss += vis[num[j]];
			}
			for(int j = beg[i]; j <= ed[i]; ++j) {
				vis[num[j]] = 0;
			}
		}
		for(int i = 1; i <= 100; ++i) {
			for(int j = 1; j <= curp; ++j) {
				s[i][j] = (pp[i - 1][j] >= 1);
				p[i][num[j]] += (s[i][j] == 1);
			}
			for(int j = 1; j <= n; ++j) {
				for(int k = beg[j]; k <= ed[j]; ++k) {
					vis[num[k]] += (s[i][k] == 1);
				}
				for(int k = beg[j], su = 0, ss = 0; k <= ed[j]; ++k) {
					pp[i][k] = su - ss;
					if(k - beg[j] >= K) {
						su -= p[i][num[k - K]];
						ss -= vis[num[k - K]];
					}
					su += p[i][num[k]];
					ss += vis[num[k]];
				}
				for(int k = beg[j]; k <= ed[j]; ++k) {
					vis[num[k]] = 0;
				}
			}
		}
		for(int i = 1, r = 0, c = 0; i <= q; ++i) {
			cin >> r >> c;
			if(p[r][c] >= 1) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
	return 0;
}
// LIST OF ACCOUNTS TO ORZ
// ORZ JXY2011 
// ORZ LITTLEACBG
// ORZ LIAOYANXU
// ORZ COMPOSITE_FUNCTION
// ORZ TIANTIAN2021

// luogu account : 
// input this string into nutrimatic.org : nA{1,}ification
// choose one among all the result, for example a string s
// then change s into all capital letters
// change all the 'I' in s to '1', 'O' to '0'
// then the username is __ s __, where the s represents the string s after all the above operations
// for example : s = notification
// then the username is __N0T1F1CAT10N__ but it's wrong
// some guesses may be required

// SOLUTION : 
// Obviously every J T4 should be easy.
// It is easy to find out that dp will be useful here.
// A possible way to dp is dp[i][j][k] representing after i steps, player j take the last step and the last number is k.
// The last two dimensions of the array ([j][k]) can be represented with a single number ([s]) representing the index of the number among all the players.
// How to transfer :
//     The player id of the last step will not be very important. Take p[i][j] as the possible ways to do exactly i steps and the last number is j. Count all the i - 1 steps possible result as 1 possible choice.
//     Then simply calculate the possible choices of each player and use a sliding window to calculate the length of the choice.
//     Corner case : 
//         The first step don't have a previous player so just calculating the 1s in the sliding window is enough.
// Pre-calculate 100 steps before questions and then O(1) answer them.
