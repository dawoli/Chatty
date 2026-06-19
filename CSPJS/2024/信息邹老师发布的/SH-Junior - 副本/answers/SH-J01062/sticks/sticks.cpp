#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int stick(int x)
{
	int ans = 0;
	int tmp = x;
	while(tmp)
	{
		int t = tmp % 10;
		ans += a[t];
		tmp /= 10;
	}
	return ans;
 } 
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
	{
		scanf("%d", &n);
		if(n == 1)
		{
			printf("-1\n");
			continue;
		} 
		for(int j = 1; j <= N; ++j)
		{
			if(stick(j) == n)
			{
				printf("%d\n", j);
				break;
			}
		}
	}
	return 0;
}
