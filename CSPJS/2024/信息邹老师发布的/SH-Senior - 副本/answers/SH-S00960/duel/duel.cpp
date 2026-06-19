#include <bits/stdc++.h>

long long n, r[100010], c, temp, len, dlt;

bool cmp(long long a, long long b)
{
	return a < b;
}

long long gainnum(long long x, long long y)
{
	if(x >= y) return 0;
	else return y - x;
}

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	std::cin >> n;
	for(long long i = 1; i <= n; i++)
		std::cin >> r[i];
	std::sort(r + 1, r + 1 + n, cmp);
	long long mx = r[1];
	
	for(long long i = 1; i <= n; i++)
	{
		if(r[i] > mx)
		{
			len = i - 1;
			temp = i - 1;
			dlt = i - 1;
			mx = r[i];
			break;
		}
	}
	for(long long i = temp; i <= n; i++)
	{
		if(r[i] > mx)
		{
			len = i - 1 - temp;
			temp = i - 1;
			dlt = std::min(len, dlt);
			c += dlt;
			dlt = len + gainnum(len, dlt);		
			mx = r[i];
		}
		if(i == n)
		{
			len = n - temp;
			dlt = std::min(len, dlt);
			c += dlt;
		}
	}
	std::cout << n - c;
	
	return 0;
}
