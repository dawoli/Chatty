#include <iostream>
using namespace std;

bool flag[4][14];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		char c1 = s[0], c2 = s[1];
		int x, y;
		switch (c1){
			case 'D': x = 0; break;
			case 'C': x = 1; break;
			case 'H': x = 2; break;
			case 'S': x = 3; break;
		}
		switch (c2){
			case 'A': y = 1; break;
			case 'T': y = 10; break;
			case 'J': y = 11; break;
			case 'Q': y = 12; break;
			case 'K': y = 13; break;
			default: y = c2 - '0';
		}
		flag[x][y] = true;
	}
	int ans = 0;
	for (int i = 0; i <= 3; i++)
		for (int j = 1; j <= 13; j++)
			if (!flag[i][j]) ans++;
	cout << ans << endl;
	return 0;
}
