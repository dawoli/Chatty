# include <iostream>
using namespace std;
const int M = 1e9 + 5;

long long n, k, a[M], x;

long long tt(int cur)
{
	long long deter = 1;
	for (int i = 1; i <= cur; i ++)
	{
		deter *= 10;
	}
	return deter;
}

long long change(long long n)
{
	long long ans = 0;
	long long t = n;
	long long cur = 0;
	while (t > 0)
	{
		ans = ans + t % 2 * tt(cur);
		t /= 2;
		cur ++;
	}
	return ans;
}

adding(int x, int y)
{
	int deterb = 0, cur = 0;
	int xk = a[x], yk = a[y];
	int maxkk = max(xk, yk);
	while (maxkk > 0)
	{
		if (xk % 10 != yk % 10)
		{
			deterb = deterb + tt(cur);
		}
		cur ++;
	}
	return deterb;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	k = change(k);
	for(int i = 1; i <= n; i ++)
	{
		cin >> x;
		a[i] = change(x);
	}
	int h1 = 0, ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i; j <= n; j ++)
		{
			for (int h = i; h <= j; h ++)
			{
				
			}
		}
	}
	return 0;
} 
