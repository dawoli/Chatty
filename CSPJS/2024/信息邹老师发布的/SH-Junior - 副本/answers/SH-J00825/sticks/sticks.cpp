#include <iostream>
using namespace std;
void f(int m,int p)
{
	cout << p;
	for (int i = 1;i <= m;i++)
		cout << 8;
	cout << endl;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n;
		if (n % 7 == 0)
			f(n / 7 - 1,8);
		else if (n % 7 == 1)
			if (n == 1)
				cout << -1 << endl;
			else
				f(n / 7 - 1,10);
		else if (n % 7 == 2)
			f(n / 7,1);
		else if (n % 7 == 3)
			if (n == 3)
				cout << 7 << endl;
			else
				f(n / 7 - 1,22);
		else if (n % 7 == 4)
			if (n == 4)
				cout << 4 << endl;
			else
				f(n / 7 - 1,20);
		else if (n % 7 == 5)
			f(n / 7,2);
		else if (n % 7 == 6)
			f(n / 7,6);
	} 
	return 0;
}
