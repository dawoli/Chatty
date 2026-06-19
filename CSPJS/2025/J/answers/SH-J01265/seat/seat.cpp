//01-11-25 08:56
#include<bits/stdc++.h>
using namespace std;

int n, m, a[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	 
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++ i)
		cin >> a[i];
	
	int t = a[1];
	sort(a + 1, a + n * m + 1);
	
	int idx = 1;
	for(; idx <= n * m && a[idx] != t; ++ idx);
	idx = n * m - idx + 1;
//	cout << idx << endl;
	int tmp = (idx + n - 1) / n;
	cout << tmp << ' ';
	if(tmp % 2)
		cout << (idx - 1) % n + 1;
	else
		cout << n - ((idx - 1) % n + 1) + 1;
	return 0;
}
