#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int n;
//vector<char> path;
//vector< vector<char> > result;
int sum[2000000] = {0};
int times = 0;

struct color_sum{
	int sumR;
	int sumB;
	int c;
};

void color(string s, int num) {
	color_sum cs[s.length()];
	if (s[0] == 'r') {
		cs[0].sumR = 1;
	} else if (s[0] == 'b') {
		cs[0].sumB = 1;
    }
	for (int i=1; i<s.length(); i++) {
		if (s[i] == 'r') {
			cs[i].sumR = cs[i-1].sumR + 1;
	    } else if (s[i] == 'b') {
	    	cs[i].sumB = cs[i-1].sumB + 1;
		}
	}
	cs[0].c = 0;
	for (int i=1; i<n; i++) {
		if (s[i] == 'r') {
			if (cs[i-1].sumR == 0) {
				cs[i].c = 0;
			} else {
				int lastIndex = 0;
				for (int j=0; j<i; j++) {
					if (s[j] == 'r') {
						lastIndex = j;
					}
				} 
				if (a[lastIndex] == a[i]) {
					cs[i].c = a[i];
				} else {
					cs[i].c = 0;
				}
			}
		} else if (s[i] == 'b') {
			if (cs[i-1].sumB == 0) {
				cs[i].c = 0;
			} else {
				int lastIndex = 0;
				for (int j=0; j<i; j++) {
					if (s[j] == 'b') {
						lastIndex = j;
					}
				} 
				if (a[lastIndex] == a[i]) {
					cs[i].c = a[i];
				} else {
					cs[i].c = 0;
				}
			}
		}
	}
	sum[num] = 0;
	for (int i=0; i<s.length(); i++) {
		sum[num] += cs[i].c;
	}
}

void dfs(int startIndex, string c) {
//	if (path.size() == n) {
//		result.push_back(path);
//		return;
//	}
	if (c.length() == n) {
		times++;
		color(c, times);
		return;
	}
//	for (int i=startIndex; i<n-(n-path.size()); i++) {
//		path.push_back(a[i]+'0');
//		dfs(startIndex+1);
//		path.pop_back();
//	}
	dfs(startIndex+1, c+'r');
	dfs(startIndex+1, c+'b');
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		times = 0;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		dfs(0, "");
		int maxIndex = 0;
		for (int i=1; i<times; i++) {
			if (sum[i] > sum[maxIndex]) {
				maxIndex = i;
			}
		}
		cout << sum[maxIndex] << endl;
	}
	return 0;
}
