#include<bits/stdc++.h>
using namespace std;
int n,k,ans = 0,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)cin >> a[i];
	int res = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			res = int(res ^ a[j]);
			if(res == k)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
