#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

int n, arr[4][14], cnt, x[130];
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	x['A'] = 1; x['T'] = 10; x['J'] = 11; x['Q'] = 12; x['K'] = 13;
	for (int i = 2; i < 10; i++) x[i + '0'] = i;
	while (n--) {
		char a, b; cin >> a >> b;
		arr[a == 'D' ? 0 : (a == 'C' ? 1 : (a == 'H' ? 2 : 3))][x[(int)b]]++;
	}
	for (int i = 0; i < 4; i++) for (int j = 1; j <= 13; j++) if (!arr[i][j]) cnt++;
    cout << cnt << endl;
	return 0;
}