#include <iostream>
using namespace std;
int n,num;
string b[5][14],c[5],d[14],a[55];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	c[1] = "D";
	c[2] = "C";
	c[3] = "H";
	c[4] = "S";
	d[1] = "A";
	d[2] = "2";
	d[3] = "3";
	d[4] = "4";
	d[5] = "5";
	d[6] = "6";
	d[7] = "7";
	d[8] = "8";
	d[9] = "9";
	d[10] = "T";
	d[11] = "J";
	d[12] = "Q";
	d[13] = "K";
	for(int i = 1;i <= 4;i++)
	{
		for(int j = 1;j <= 13;j++)
		{
			b[i][j] = c[i] + d[j];
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= 4;j++)
		{
			for(int k = 1;k <= 13;k++)
			{
				if(a[i] == b[j][k])
				{
					num++;
					b[j][k] = "0";
					continue;
				}
			}
		}
	}
	cout << 52 - num;
	return 0;
}
