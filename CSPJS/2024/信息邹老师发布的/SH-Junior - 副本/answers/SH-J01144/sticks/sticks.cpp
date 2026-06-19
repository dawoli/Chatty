#include <bits/stdc++.h>
using namespace std;
int ans[8] = {-1,-1,1,7,4,2,6,8};
void print8(int x)
{
	for(int i = 1;i <= x/7;i++)cout << "8";
	cout << endl;
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n < 2)
		{
			cout << -1 << endl;
			continue;
		}
		if(n <= 7)
		{
			cout << ans[n] << endl;
			continue;
		}
		if(n % 7 == 1)
		{
			cout << "10";
			print8(n-8);
		}
		else if(n % 7 == 2)
		{
			cout << "1";
			print8(n-2);
		}
		else if(n % 7 == 3)
		{
			cout << "22";
			print8(n-10);
		}
		else if(n % 7 == 4)
		{
			cout << "20";
			print8(n-11);
		}
		else if(n % 7 == 5)
		{
			cout << "2";
			print8(n-5);
		}
		else if(n % 7 == 6)
		{
			cout << "6";
			print8(n-6);
		}
		else if(n % 7 == 0)
		{
			print8(n);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
