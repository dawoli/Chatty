#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			if (s[i] < s[i + 1])
			{
				int n = s[i];
				s[i] = s[i + 1];
				s[i + 1] = n;
			}
		}
	}
	cout << s << endl;
	return 0;
}
