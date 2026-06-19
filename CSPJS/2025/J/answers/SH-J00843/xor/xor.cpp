#include <bits/stdc++.h>
using namespace std;

long long n, k, a[500010], s[500010];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool isA = true;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = a[i];
		if(a[i] != 1)
		{
			isA = false;
		}
	}
	if(isA == true)
	{
		cout << n << endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	long long mid = 1, cnt = 0;
	for(long long i = 1; i <= n; i++)
	{
		long long sum = a[mid];
		for(long long j = mid; j <= n; j++)
		{
			if(sum == k)
			{
				mid = j;
				cnt++;
				break;
			}
			sum += s[j] | s[j + 1];
			s[j + 1] = s[j] | s[j + 1];
		}
		mid++;
	}
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
