#include <bits/stdc++.h> 
using namespace std;

int t;
int n;

void solve()
{
	cin >> n;
	if (n<=1)
	{
		cout << -1;
		return ;
	} 
	int s=n/7,m=n%7;
	if (m==0)
	{
		for (int i=1;i<=s;i++)
			cout << 8;
	}
	else if (m==1)
	{
		cout << 10;
		for (int i=1;i<=s-1;i++)
			cout << 8;
	}
	else if (m==2)
	{
		cout << 1;
		for (int i=1;i<=s;i++)
			cout << 8;
	}
	else if (m==3)
	{
		if (s>1)
		{
			cout << 200;
			for (int i=1;i<=s-2;i++)
				cout << 8;
		}
		else if (s==1)
		{
			cout << 22;
		}
		else
		{
			cout << 7;
		}
		
	}
	else if (m==4)
	{
		if (s<1)
		{
			cout << 4;
		}
		else if (s>=1)
		{
			cout << 20;
			for (int i=1;i<=s-1;i++)
				cout << 8;
		}
	}
	else if (m==5)
	{
		cout << 2;
		for (int i=1;i<=s;i++)
			cout << 8;
	}
	else if (m==6)
	{
		cout << 6;
		for (int i=1;i<=s;i++)
			cout << 8;
	}
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	while (t--)
	{
		solve();
		cout << endl;
	}
	return 0;
}
