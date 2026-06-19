#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const int P = 998244353;
int a[N];
int n;
int num[N];
int cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int t = 1;t <= n;t++)
	{
		scanf("%d",&a[t]);
	}
	for(int t = 1;t < (1 << n);t++) 
	{
		for(int i = n - 1;i >= 0;i--)
		{
			if((t >> i) & 1)
			{
				num[i + 1] = 1; 
			}
		}
		int sum = 0;
		int maxn = -1;
		for(int i = 1;i <= n;i++) if(num[i])
		{
			sum += a[i];
			maxn = max(maxn,a[i]);
			num[i] = 0;
		}
		if(maxn * 2 < sum)
		{
			cnt++;
			cnt %= P; 
		}
	}
	printf("%d",cnt);
	return 0;
}
