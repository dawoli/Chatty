#include<bits/stdc++.h>
using namespace std;
int modnum = 998244353;
int n,length[5050];
long long ans = 0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> length[i];
	int sum = 0,cnt = 0,maxn = 0;
	for(int i = 1;i <= n;i++)
	{
		maxn = 0;
		sum = 0;
		cnt = 0;
		for(int j = i;j <= n;j++)
		{
			sum += length[i];
			cnt++;
			maxn = max(maxn,length[j]);
			if(cnt >= 3 && sum > maxn * 2)ans++;
		}
	}
	ans %= modnum;
	cout << ans << endl;
	return 0;
}
