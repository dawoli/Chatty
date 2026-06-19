#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], sum, pos;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	sum = n * m;
	cin >> a[1];
	int r = a[1];
	for (int i = 2; i <= sum; i++)
		cin >> a[i];
	sort(a + 1, a + sum + 1, cmp);
	for (int i = 1; i <= sum; i++)
		if (a[i] == r){
			pos = i;
			break;
		}
	pos--;
	int h = pos % n + 1;
	int l = pos / n + 1;
	if (l % 2 == 0)
		h = n - h + 1;
	printf("%d %d\n", l, h);
	return 0;
}

