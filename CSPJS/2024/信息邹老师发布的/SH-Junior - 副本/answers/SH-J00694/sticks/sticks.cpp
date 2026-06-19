#include <bits/stdc++.h>
using namespace std;
int n;
char num2[10] = {'0','0','1','7','4','2','0','8'};
string st[] = {"","10","1","200","20","2","6"};
int di[] = {0,-1,0,-2,-1,0,0};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n < 2)
		{
			cout << -1 << endl;
			continue;
		}
		if(n < 7)
		{
			cout << num2[n] << endl;
			continue;
		}
		int mod = n % 7;
		string ans = st[mod];
		int k = n / 7; 
		for(int i = 1;i <= k + di[mod];i++)
		{
			ans += "8";
		}
		cout << ans << endl;
	}
	return 0;
}
