#include <bits/stdc++.h>
using namespace std;
int n , k, res, cnt = 0;
struct num{
	int s;
	bool used = false;
}a[500007];
bool check(int L, int R)
{
	for(int i = L ; i <= R ; i ++)
	{
		if(a[i].used == true)
		{
			return true;
		}
	}
	return false;
}
bool st_(int L, int R)
{
	for(int i = L ; i <= R ; i ++)
	{
		a[i].used = true;
	} 
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin >> n >> k;
	for(int i = 1; i <=n ; i ++)
	{
		cin >> a[i].s;
	}
	for(int i = 1; i <= n ; i++)
	{
		res = a[i].s;
		for(int j = i ; j <= n ; j ++)
		{
			if(j==i)
			{
				if(res == k)
				{
					a[i].used = true;
					cnt = cnt + 1;
					break;
				}
			}else
			{
				res = res xor a[j].s;
				bool ck = check(i, j);
				if(res == k && !ck)
				{
					cnt = cnt +1;
					st_(i,j);
					break;
				}
			}
		}
	}
	printf("%d", cnt-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
