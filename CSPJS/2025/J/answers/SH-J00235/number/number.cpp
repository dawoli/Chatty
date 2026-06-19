#include <bits/stdc++.h>
using namespace std;
string n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n.push_back(s[i]);
		}
	}
	sort(n.rbegin(), n.rend()); 
	cout << n << "\n";
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
It preferred disappearing alone, slowly at Nimo Point,
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
