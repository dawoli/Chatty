#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int p[10] {};
	string s, nums;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			p[s[i] - '0']++;
		}
	}
	for (int i = 9; i + 1; i--)
	{
		for (int j = 0; j < p[i]; j++)
		{
			nums += ('0'+i);
		}
	}
	if (nums[0] == '0') cout << 0;
	else cout << nums;
	return 0;
}
