#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++)
		cin >> a[i];
	int score = a[1];
	sort(a + 1, a + 1 + m * n, greater<int>());
	int l = 1, r = m * n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (a[mid] == score) {
			int x, y;
			x = ceil((double) mid / n); // 2 % 2 == 0
			y = (x & 1 ? (mid % n ? mid % n : n) : (mid % n ? n - mid % n + 1: 0));
			cout << x << ' ' << y << "\n";
			break;
		} else if (a[mid] > score)
			l = mid + 1;
		else
			r = mid - 1;
	}// 7 % 3 = 1 7 % 4 = 3
	return 0;
}
// xorÊ«ÈË£¿ 

/**
Lonely Rain

The rain found itself at Nimo Point.
All things around it were the sounds of waves.
It felt extremely lonely.

As soon as it would disappear soon,
A typhoon spawned and made it live longer,
And brought it to South America.
Rain was excited,
It wanted more kinds of sound,
As well as more interests.

Which waited for it were bad words, however,
It made everything destroyed,
¡ª¡ªAlthough it was harmless before. 

Rain regretted.
It preferred disappearing alone, slowly at Nimo Point.
To being complained,
	Being remembered,
		Forever. 

With wishes,
	Anger,
		And regrettation,
¡ª¡ªSoundlessly, 
	It disappeared in the mountain. 
Sep. 29th, Translated from Chinese on Oct. 31st.
By Angus.
*/
