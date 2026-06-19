#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 107;
int n, m, a[N], tgt;

/* 先列再行 */ 

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for(int i=1; i<=n*m; i++) cin >> a[i];
	tgt = a[1];
	sort(a+1, a+1+n*m);
	reverse(a+1, a+1+n*m);
	int nid = -1;
	for(int i=1; i<=n*m; i++) if(a[i] == tgt) nid = i;
//	cout << tgt << ' ' << nid << endl;
	int row, col;
	col = (nid - 1) / n + 1;
	row = nid - (col - 1) * n;
	if(col % 2 == 0) row = n + 1 - row;
	cout << col << ' ' << row;
	return 0;
}

 
