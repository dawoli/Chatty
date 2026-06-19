#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<int> v(10,0);
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			v[s[i]-48]++;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 1;j <= v[i];j++)
		{
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
