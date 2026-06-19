#include <bits/stdc++.h>
using namespace std;
priority_queue<int> a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a.push(s[i] - '0');
			cnt++;
		}
	}
	for(int i = 1;i <= cnt;i++)
	{
		cout << a.top();
		a.pop();
	}
	return 0;
}
