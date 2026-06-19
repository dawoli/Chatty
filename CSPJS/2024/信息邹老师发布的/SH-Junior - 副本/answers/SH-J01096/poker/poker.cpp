#include <string>
#include <iostream>
#include <map>
using namespace std;
int n, ans;
map <string, int> mp;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		if (mp[str] == 0)
		{
			mp[str] = 1;
			ans++;
		}
	}
	cout << 52 - ans << endl;
}
