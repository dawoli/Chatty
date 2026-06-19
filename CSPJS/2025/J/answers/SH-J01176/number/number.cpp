#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
	string k; cin >> k;
	vector <int> a;
	for (int i = 0; i < k.size (); i ++)
		if ('0' <= k [i] && k [i] <= '9')
			a.push_back (k [i] - '0');
	sort (a.begin (), a.end (), greater <int> ());
	for (int i = 0; i < a.size (); i ++)
		cout << a [i];
}
