#include<bits/stdc++.h>
using namespace std;
int t, n, book[10] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out","w", stdout);
	cin >> t;
	while(t--)
	{
		int flag = 0; // ÊÇ·ñ 
		cin >> n;
		if(n <= 1)
		{
			cout << -1 << '\n';
			continue;
		}
		for(int i = 1; i <= 8888888; i++)
		{
			int num = 0;
			int k = i;
			while(k)
			{
				num += book[k % 10];
				k /= 10;
			}
			if(num == n)
			{
			    flag = 1;
				cout << i << endl;
				break;
			}
		}
		if(!flag)
		{
			cout << "-1\n";
		}
	}
	return 0;
}
