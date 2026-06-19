#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	string s;
	cin >> s;
	vector<int> vec;
	for(int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			vec.push_back(s[i] - '0');
		}
	}
	sort(vec.begin(), vec.end(), [](int x, int y)
	{
		return x > y;
	});
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
