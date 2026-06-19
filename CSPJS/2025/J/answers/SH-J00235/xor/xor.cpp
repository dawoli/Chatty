#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k;
int a[N], all, f;
long long ans; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f ^= a[i];
		if (f == k) {
			ans++, f = 0;
		}
	}
	cout << ans; 
	return 0;
} // 我没招了 凹不动了

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
——Although it was harmless before.

Rain regretted.
It preferred disappearing alone, slowly at Nimo Point,
To being complained,
	Being remembered,
		Forever.

With wishes,
	Anger,
		And regrettation,
——Soundlessly,
	It disappeared in the mountain.
Sep. 29th, Translated from Chinese on Oct. 31st.
By Angus. 
*/

