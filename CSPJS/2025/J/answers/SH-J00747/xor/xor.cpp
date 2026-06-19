#include <iostream>
using namespace std;
#define ll long long
int n;
ll k, a[500001];
bool ifa = 1, ifb = 1;
void solveA()
{
	if (k == 0) cout << n / 2;
	else if (k == 1) cout << n;
	else cout << 0;
}
void solveB()
{
	if (k == 1)
	{
		ll cnt = 0;
		for (int i = 1; i <= n; i++) 
			if (a[i] == 1)
				++cnt;
		cout << cnt;
	} 
	else
	{
		ll cnt = 0, lx1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0)
			{
				lx1 = 0;
				++cnt;
			}
			else
			{
				++lx1;
				if (lx1 == 2) 
				{
					lx1 = 0;
					++cnt;
				}
			}
		}
		cout << cnt;
	}
}
void solvebl()
{
	ll cnt = 0;
	int nowr = 0;
	for (int i = 1; i <= n; i++)
	{
		ll tot = 0;
		for (int j = i; j >= nowr + 1; j--)
		{
			tot ^= a[j];
			if (tot == k)
			{
				++cnt;
				nowr = max(nowr, i);
				tot = 0;
				//puts("");
				break;
 			}
		}
	}
	cout << cnt;
}
int main() 
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if (a[i] != 0) ifa = 0;
		if (a[i] > 1) ifb = 0;
	}
	if (ifa)
	{
		solveA();
		return 0;
	}
	if (ifb)
	{
		solveB();
		return 0;
	}
	solvebl();
	return 0;
}
/*
注意到nowr = max(nowr, i)
所以应该复杂度O(n)，期望AC on 10:45 
*/
