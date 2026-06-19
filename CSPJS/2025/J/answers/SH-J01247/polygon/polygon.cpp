#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];

int b[5005];

long long ans;
long long const Mod = 998244353;

bool check(int q, int maxn, int step) {
	long long total = 0;
	for (int i = 1; i < step; i++) {
		total += b[i];
	}
	maxn = max(a[q],maxn);
	if (total + a[q] > maxn *2) {
		return true;
	}
	else return false;
}

bool flag[5005];
void dfs(int step, int maxn,int last) {
	if (step > n) {
		return ;
	}
	for (int i = last+1; i <= n; i++) {
		if (!flag[i]) {
			if (step >= 3 && check(i,maxn,step)) {
				for (int i = 1; i < step; i++) {
					cout << b[i] << " ";
				}
				cout << a[i];
				cout << endl;
				ans++;
			}
			b[step] = a[i];
			flag[i] = true;
			dfs(step+1,max(maxn,b[step]),i);
			flag[i] = false;
		}
	}
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1,0,0);
	cout << ans << endl;
	return 0;
} 
