#include <iostream>
using namespace std;
bool a[5][15];
int flower(char x) {
	if(x == 'D')return 1;
	if(x == 'C')return 2;
	if(x == 'H')return 3;
	if(x == 'S')return 4;
}
int number(char x) {
	if('2' <= x && x <= '9')return x - '0';
	if(x == 'T')return 10;
	if(x == 'J')return 11;
	if(x == 'Q')return 12;
	if(x == 'K')return 13;
	if(x == 'A')return 1;
}
void reads(string s) {
	int x = flower(s[0]);
	int y = number(s[1]);
	a[x][y] = 1;
}
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		reads(s);
	}
	int ans = 0;
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 13; j++) {
			ans += 1 - a[i][j];
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

