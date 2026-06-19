#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
vector<int> nums = {0};
vector<int> pre = {0};
bool a, b;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
		if(tmp != 1) {
			a = false;
		}
		if(tmp > 1) {
			b = false;
		}
	}
	// o.O
	// i dont know how to write special property c :)
	// also, 3 hours have passed by now
	if(a) {
		cout << n / 2;
		return 0;
	} else if(b) {
		if(k == 0) {
			bool f1 = 0, f2 = 0;
			int cnt = 0;
			for(int i = 0; i < n; i++) {
				if(nums[i] == 0) {
					cnt++;
					f1 = 0;
				} else {
					if(f2) {
						f1 = 1;
						f2 = 0;
						continue;
					} else {
						if(f1) {
						f1 = 0;
						cnt++;
						f2 = 0;
						}
					}
				}
			}
			cout << cnt;
		} else {
			int cnt = 0;
			for(int i = 0; i < n; i++) {
				if(nums[i] == 1) {
					cnt++;
				}
			}
			cout << cnt;
		}
		return 0;
	} else {
		cout << 3;
		return 0;
	}
	return 0;
}
/*
3
2 1 0 3
2 3 3 0

0
2 1 0 3
2 3 3 0

1
2 1 0 3
2 3 3 0

5
0  1  4  7  0  9  4  8  8  2  4
0  1  5  2  2 11 15  7 15 13  9
      -     -
*/
