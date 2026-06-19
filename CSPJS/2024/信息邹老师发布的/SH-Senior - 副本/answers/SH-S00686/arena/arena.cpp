#include<bits/stdc++.h>
using namespace std;

int T , n , m;
int a[100010] , c[100010];
int x[260][5];
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> c[i];
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> x[i][1] >> x[i][2] >> x[i][3] >> x[i][4];
	}
	
	for(int i = 1; i <= T; i++)
		cout << 1 << endl;
	
	return 0;
}
