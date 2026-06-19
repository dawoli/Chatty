#include <bits/stdc++.h>
using namespace std;

const bool DEBUG = false;

void testIO()
{
	int n;
	cin >> n;
	cout << n << endl;
}

int n;
set<string> s;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	// testIO();
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		string x;
		cin >> x;
		if (!s.count(x)) s.insert(x);
	}
	cout << 52 - s.size() << endl;
	return 0;
}