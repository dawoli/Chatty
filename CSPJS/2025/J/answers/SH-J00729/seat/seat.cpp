#include<bits/stdc++.h>
using namespace std;
int n, m, cc, rr, cnt, now, a[105];

void dfs(int c, int r, int tot){
	if (tot == now){
		cc = c;
		rr = r;
		return;
	}
	if (c % 2 == 1){
		if (r + 1 > n)
			dfs(c + 1, n, tot + 1);
		else
			dfs(c, r + 1, tot + 1);
	}
	else{
		if (r - 1 < 1)
			dfs(c + 1, 1, tot + 1);
		else
			dfs(c, r - 1, tot + 1);
	}
} 

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
		cin >> a[i];
	cnt = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; ++i){
		if (a[i] == cnt){
			now = i;
			break;
		}
	}
	now = n * m - now + 1;
	dfs(1, 1, 1);
	cout << cc << ' ' << rr;
	return 0;
}
