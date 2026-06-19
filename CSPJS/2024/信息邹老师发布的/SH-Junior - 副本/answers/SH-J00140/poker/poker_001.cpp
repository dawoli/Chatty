#include<bits/stdc++.h>
using namespace std;

int f = 0;

string a[55];

bool r(string s)
{
	for(int i = 1; i <= f; i++)
	{
		if(a[i] == s)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if(!r(s))
		{
			f++;
			a[f] = s;
		}
	}
	cout << 52 - f;
	return 0;
}
/*
freopen(".in","r",stdin);
	freopen(".out","w",stdout);

*/
