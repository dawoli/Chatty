#include <bits/stdc++.h>
/*
数学题。
先二分定位分数位置，然后分类讨论在那一列，就非常好做了
*//*
luogu 782768 #define int long long
feropen froepen freopen
freopen("seat.out", "r", stdin);
freopen("seat.in", "w", stdin);
*/
using namespace std;
bool cmp(int a, int b){ return a > b; }
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, p;
	cin >> n >> m >> p;
	vector <int> vec = {p};
	for (int i = 1, x; i < n * m; i ++){
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	int where = lower_bound(vec.begin(), vec.end(), p) - vec.begin() + 1;
	where = n * m - where + 1;
	// cout << where << '\n';
	int x, y;
	x = ceil(1.0f * where / n);
	y = (where - 1) % m + 1;
	if (x % 2 == 0) y = m + 1 - y; 
	cout << x << ' ' << y;
} 
