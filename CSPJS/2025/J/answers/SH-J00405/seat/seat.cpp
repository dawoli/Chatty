#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
int a[MAXN][MAXN];

int main(){
	freopen("seat.in", r, stdin);
	freopen("seat.out", w, stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0 ; j < m; j++){
			cin >> a[i][j];
		}
	}
	cout << m << " " << n;
	return 0;
} 
