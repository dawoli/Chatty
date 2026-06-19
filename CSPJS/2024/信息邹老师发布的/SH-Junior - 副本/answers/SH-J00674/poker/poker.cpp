#include<bits/stdc++.h>
using namespace std;
long long vis[100], n, ans;
string a;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		if(a[0] == 'D')
		{
			if(a[1] == 'A')
			{
				vis[1]++;
			}
			else if(a[1] == '2')
			{
				vis[2]++;
			}
			else if(a[1] == '3')
			{
				vis[3]++;
			}
			else if(a[1] == '4')
			{
				vis[4]++;
			}
			else if(a[1] == '5')
			{
				vis[5]++;
			}
			else if(a[1] == '6')
			{
				vis[6]++;
			}
			else if(a[1] == '7')
			{
				vis[7]++;
			}
			else if(a[1] == '8')
			{
				vis[8]++;
			}
			else if(a[1] == '9')
			{
				vis[9]++;
			}
			else if(a[1] == 'T')
			{
				vis[10]++;
			}
			else if(a[1] == 'J')
			{
				vis[11]++;
			}
			else if(a[1] == 'Q')
			{
				vis[12]++;
			}
			else if(a[1] == 'K')
			{
				vis[13]++;
			}
		}
		else if(a[0] == 'C')
		{
			if(a[1] == 'A')
			{
				vis[1 + 13]++;
			}
			else if(a[1] == '2')
			{
				vis[2 + 13]++;
			}
			else if(a[1] == '3')
			{
				vis[3 + 13]++;
			}
			else if(a[1] == '4')
			{
				vis[4 + 13]++;
			}
			else if(a[1] == '5')
			{
				vis[5 + 13]++;
			}
			else if(a[1] == '6')
			{
				vis[6 + 13]++;
			}
			else if(a[1] == '7')
			{
				vis[7 + 13]++;
			}
			else if(a[1] == '8')
			{
				vis[8 + 13]++;
			}
			else if(a[1] == '9')
			{
				vis[9 + 13]++;
			}
			else if(a[1] == 'T')
			{
				vis[10 + 13]++;
			}
			else if(a[1] == 'J')
			{
				vis[11 + 13]++;
			}
			else if(a[1] == 'Q')
			{
				vis[12 + 13]++;
			}
			else if(a[1] == 'K')
			{
				vis[13 + 13]++;
			}
		}
		else if(a[0] == 'H')
		{
			if(a[1] == 'A')
			{
				vis[1 + 26]++;
			}
			else if(a[1] == '2')
			{
				vis[2 + 26]++;
			}
			else if(a[1] == '3')
			{
				vis[3 + 26]++;
			}
			else if(a[1] == '4')
			{
				vis[4 + 26]++;
			}
			else if(a[1] == '5')
			{
				vis[5 + 26]++;
			}
			else if(a[1] == '6')
			{
				vis[6 + 26]++;
			}
			else if(a[1] == '7')
			{
				vis[7 + 26]++;
			}
			else if(a[1] == '8')
			{
				vis[8 + 26]++;
			}
			else if(a[1] == '9')
			{
				vis[9 + 26]++;
			}
			else if(a[1] == 'T')
			{
				vis[10 + 26]++;
			}
			else if(a[1] == 'J')
			{
				vis[11 + 26]++;
			}
			else if(a[1] == 'Q')
			{
				vis[12 + 26]++;
			}
			else if(a[1] == 'K')
			{
				vis[13 + 26]++;
			}
		}
		else if(a[0] == 'S')
		{
			if(a[1] == 'A')
			{
				vis[1 + 39]++;
			}
			else if(a[1] == '2')
			{
				vis[2 + 39]++;
			}
			else if(a[1] == '3')
			{
				vis[3 + 39]++;
			}
			else if(a[1] == '4')
			{
				vis[4 + 39]++;
			}
			else if(a[1] == '5')
			{
				vis[5 + 39]++;
			}
			else if(a[1] == '6')
			{
				vis[6 + 39]++;
			}
			else if(a[1] == '7')
			{
				vis[7 + 39]++;
			}
			else if(a[1] == '8')
			{
				vis[8 + 39]++;
			}
			else if(a[1] == '9')
			{
				vis[9 + 39]++;
			}
			else if(a[1] == 'T')
			{
				vis[10 + 39]++;
			}
			else if(a[1] == 'J')
			{
				vis[11 + 39]++;
			}
			else if(a[1] == 'Q')
			{
				vis[12 + 39]++;
			}
			else if(a[1] == 'K')
			{
				vis[13 + 39]++;
			}
		}
	}
	for(int i = 1; i <= 52; i++)
	{
		if(vis[i] == 0)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
