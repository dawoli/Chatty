#include <bits/stdc++.h>
using namespace std;
int n;
string x;
vector <string> vec;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	while (n--)
	{
		cin >> x;
		bool f = 1;
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] == x)
			{
				f = 0;
				break;
			}
		}
		if (f) vec.push_back(x);
	}
	cout << 52 - vec.size();
	return 0;
}
