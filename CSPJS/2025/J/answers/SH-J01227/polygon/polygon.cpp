#include <bits/stdc++.h> 
using namespace std;
int n,c[114514],cnt = 0,a[114514];
void dfs(int p)
{
	if(p > n)
	{
		int sam = 0,maxn = -11,sum = 0;
		for(int i = 1;i <= n;i++)
		{
			int dick = c[i] * a[i];
			if(dick)
			{
				sam += dick;
				maxn = max(maxn,dick);
				sum++;
			}
		}
		if((sam > maxn * 2) && sum >= 3)
		{
			cnt++;
		}
		return;
	}
	c[p] = 1;
	dfs(p+1);
	c[p] = 0;
	dfs(p+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	dfs(1);
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
