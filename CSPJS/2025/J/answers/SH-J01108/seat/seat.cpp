#include <bits/stdc++.h>	// 先列再行 
using namespace std;
int n, m, a[15][15], s[205], r, x, y, head;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)	cin >> s[i];
	r = s[1];
	sort(s + 1, s + n * m + 1, cmp);
	x = 1, y = 1;
	while(true){
		if(y == m){
			if(y % 2 == 0 && x == 1)	{
				a[x][y] = s[++head];
				if(a[x][y] == r)	{
					cout << y << " " << x;
					return 0;
				}
				break;
			}
			if(y % 2 == 1 && x == n)	{
				a[x][y] = s[++head];
				if(a[x][y] == r)	{
					cout << y << " " << x;
					return 0;
				}
				break;
			}
		}
		a[x][y] = s[++head];
		if(a[x][y] == r)	{
			cout << y << " " << x;
			return 0;
		}
		if(y % 2 == 1 && x == n){
			y++;
		}
		else if(y % 2 == 0 && x == 1){
			y++;
		}
		else if(y % 2 == 1){
			x++;
		}
		else if(y % 2 == 0){
			x--;
		}
	}
	
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	return 0;
}

