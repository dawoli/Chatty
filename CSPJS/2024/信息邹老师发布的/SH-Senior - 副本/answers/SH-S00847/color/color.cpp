#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[200010] , c[200010] , n , ans;
bool f[200010];

void dfs(int st , int lstb , int lstr , int sum)
{
	if (st > n)
	{
		// if (sum > ans)
		// {
		// 	cout << ans << ":\n";
		// 	for (int i = 1; i <= n; i++)
		// 	{
		// 		if (f[i]) cout << "b ";
		// 		else cout << "r ";
		// 	}
		// 	cout << endl;
		// }
		ans = max(ans , sum);
		return;
	}
	// red
	// printf("col=red,lstr=%d,a[lstr]=%d,st=%d,a[st]=%d,op=" , lstr , a[lstr] , st , a[st]);
	f[st] = false;
	if (lstr == 0)
	{
		// printf("#1(+0),sum=%d\n" , sum);
		dfs(st + 1 , lstb , st , sum);
	}
	else if (a[lstr] == a[st])
	{
		// printf("#2(+a[lstr]),sum=%d\n" , sum + a[lstr]);
		dfs(st + 1 , lstb , st , sum + a[lstr]);
	}
	else
	{
		// printf("#3(+0),sum=%d\n" , sum);
		dfs(st + 1 , lstb , st , sum);
	}
	// blue
	// printf("col=red,lstr=%d,a[lstr]=%d,st=%d,a[st]=%d,op=" , lstr , a[lstr] , st , a[st]);
	f[st] = true;
	if (lstb == 0)
	{
		// printf("#1(+0),sum=%d\n" , sum);
		dfs(st + 1 , st , lstr , sum);
	}
	else if (a[lstb] == a[st])
	{
		// printf("#2(+a[lstb]),sum=%d\n" , sum + a[lstb]);
		dfs(st + 1 , st , lstr , sum + a[lstb]);
	}
	else 
	{
		// printf("#3(+0),sum=%d\n" , sum);
		dfs(st + 1 , st , lstr , sum);
	}
}

int main()
{
	freopen("color.in" , "r" , stdin);
	freopen("color.out" , "w" , stdout);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		ans = 0;
		dfs(1 , 0 , 0 , 0);
		cout << ans << endl;
	}
	return 0;
}