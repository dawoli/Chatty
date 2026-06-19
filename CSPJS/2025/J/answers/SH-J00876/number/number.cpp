#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool flag = false;
	string s;
	cin >> s;
	sort (s.begin(),s.end());
	for (int i = (int)(s.size() - 1);i >= 0;i--)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
	        flag = true;		
		}
		if (flag)
		{
			cout << s[i];
		}
	}
	return 0;
}
