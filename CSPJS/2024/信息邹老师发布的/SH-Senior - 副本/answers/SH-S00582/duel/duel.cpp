#include <bits/stdc++.h>

using namespace std;

int cards[114514];
int cnt[114514];
int atk[114514];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	int mxr = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
		mxr = max(mxr, cards[i]);
		cnt[cards[i]]++;
	}

	int prev = -1;
	int lft = n;
	for (int i = 1; i <= mxr; i++) {
		if (cnt[i] == 0) continue;
		if (prev != -1) {
			if (cnt[prev] >= cnt[i]) {
				cnt[prev] -= cnt[i];
				lft -= cnt[i];
				atk[i] += cnt[i];
			} else {
				atk[i] += cnt[prev];
				lft -= cnt[prev];
				cnt[prev] = 0;
			}
			
			prev = i;
		} else prev = i;
	}
	
	cout << lft;
} 
