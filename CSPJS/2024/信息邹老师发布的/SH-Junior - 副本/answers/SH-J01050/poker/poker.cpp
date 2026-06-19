#include <iostream>
using namespace std;
int n, num, ans;
bool b[52];
char fir[4] = {'D', 'C', 'H', 'S'}, sec[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
string x, a[52];
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		for(int j = 0;j < 4;j++)
		{
			for(int k = 0;k < 13;k++)
			{
				if(x[0] == fir[j] && x[1] == sec[k])
				{
					b[j * 13 + k] = 1;
				}
			}
		} 
	}
	for(int i = 0;i < 52;i++)
	{
		if(b[i] == 0)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
