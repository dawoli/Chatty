#include <bits/stdc++.h>
using namespace std;
int n , i , l , _n [100] , cnt = 0;
char _num [100] , cd , hh;
bool d [20] , c [20] , h [20] , s [20];
int main () {
	freopen ("poker.in" , "r" , stdin);
	freopen ("poker.out" , "w" , stdout);
	memset (d , 1 , sizeof (d));
	memset (c , 1 , sizeof (c));
	memset (h , 1 , sizeof (h));
	memset (s , 1 , sizeof (s));
	cin >> n;
	for (i = 1;i <= n;i ++) {
		cin >> cd >> _num [i];
		_n [i] = _num [i] - '0';
		if (_num [i] == 'A') _n [i] = 1;
		else if (_num [i] == 'T') _n [i] = 10;
		else if (_num [i] == 'J') _n [i] = 11;
		else if (_num [i] == 'Q') _n [i] = 12;
		else if (_num [i] == 'K') _n [i] = 13;
		if (cd == 'D') d [_n [i]] = 0;
		else if (cd == 'C') c [_n [i]] = 0;
		else if (cd == 'H') h [_n [i]] = 0;
		else s [_n [i]] = 0;
	}
	for (i = 1;i <= 13;i ++) {
		if (d [i]) cnt ++;
		if (c [i]) cnt ++;
		if (h [i]) cnt ++;
		if (s [i]) cnt ++;
	}
	cout << min (52 , cnt);
	return 0;
}
