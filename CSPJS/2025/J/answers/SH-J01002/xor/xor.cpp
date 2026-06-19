#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct Gru{
	int beg, end;
};

bool cmp(Gru x, Gru y) {
	return x.end<y.end;
}

const int N = 1e3+10;
int ls[N], num[N][N], n, k;
vector<Gru>group;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin>>x;
		for (int j = 1; j <= i; j ++) {
			num[j][i] = num[j][i-1]^x;
			if (num[j][i]==k&&ls[j] == 0) {
				ls[j] = i;
				group.push_back({j, i});
			}
		}
	}
	sort(group.begin(), group.end()-1, cmp);
	int end = 0, ans = 0;
	for (int i = 0; i < group.size(); i ++) {
		if (group[i].beg>end) {
			ans++;
			end = group[i].end;
		}
	}
	cout<<ans;
	return 0;
}
