#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int s[n*m+5];
	for (int i = 1;i <= n * m;i ++)
	{
		cin >> s[i];
	}
	int R = s[1],num = 0;
	for (int i = 1;i <= n * m;i ++)
	{
		for (int j = i + 1;j <= n * m;j ++)
		{
			if (s[i] < s[j])
			{
				swap (s[i],s[j]);
			}
		}
	}
	for (int i = 1;i <= n * m;i ++)
	{
		if (s[i] == R)
		{
			num = i;
			break;
		}
	} 
	//求出小R排名 
	int M,N;
	if (num % n == 0)
	{
		M = num / n - 1;
		N = n;	
	}
	else
	{
		M = num / n;
		N = num % n;	
	}
	if (M % 2 == 0)
	{
		cout << M+1 << " " << N << endl;
	}
	else
	{
		cout << M+1 << " " << n-N+1 << endl;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
