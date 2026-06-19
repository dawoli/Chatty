#include<bits/stdc++.h>
using namespace std;
map<int,string> mp = {{2,"1"},{3,"7"},{4,"4"},{5,"2"},{6,"6"},{7,"8"},{8,"10"}};
int t;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		int n;
		cin >> n;
		if(n <= 1)
		{
			cout << -1 << endl;
			continue;
		}
		int x = n % 7,y = n / 7;
		if(x == 1)
		{
			x = 8;
			y--;
		}
		string ans = mp[x];
		{
			for(int i = 0;i < y;i++)
			{
				ans = ans + '8';
			}
		}
		cout << ans << endl;
	}
	return 0;
}
