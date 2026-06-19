#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[1000010];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	int n = s.size();
	
	int t = 1;
	for(int i = 0; i < n; i++)
	{
		if(int(s[i]) >= '0' && int(s[i]) <= '9')
		{
			a[t] = int(s[i]) - 48;
			t++;
		}
	}
//	
//	for(int i = 1; i <= t - 1; i++)
//	{
//		cout << a[i] << " ";
//	}

	sort(a + 1, a + t + 1);
	
	for(int i = t; i >= 2; i--)
	{
		cout << a[i];
	}
	
	return 0;
} 
