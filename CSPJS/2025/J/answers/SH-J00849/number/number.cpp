#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int S = s.size();
	vector<int> a;
	for(int i = 0; i < S; i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			a.push_back(s[i] - '0');
		}
	}
	sort(a.begin(), a.end());
	int b = a.size();
	for(int i = b - 1; i >= 0; i--)
	{
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
