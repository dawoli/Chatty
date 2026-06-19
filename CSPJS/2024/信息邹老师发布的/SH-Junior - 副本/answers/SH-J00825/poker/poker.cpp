#include <iostream>
using namespace std;
bool a[4][14];
string m;int p,n;
void f(int b,char q)
{
	if (q <= '9')
		a[b][q - '0'] = true;
	else if (q == 'A')
		a[b][1] = true;
	else if (q == 'T')
		a[b][10] = true;
	else if (q == 'J')
		a[b][11] = true;
	else if (q == 'Q')
		a[b][12] = true;
	else
		a[b][13] = true;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> m;
		if (m[0] == 'D')
			f(0,m[1]);
		else if (m[0] == 'C')
			f(1,m[1]);
		else if (m[0] == 'H')
			f(2,m[1]);
		else
			f(3,m[1]);
	}
	for (int i = 0;i < 4;i++)
		for (int j = 1;j <= 13;j++)
			if (!a[i][j])
				p++;
	cout << p;
	return 0;
}
