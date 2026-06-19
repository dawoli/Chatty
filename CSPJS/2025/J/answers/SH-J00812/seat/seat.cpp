#include <bits/stdc++.h>
using namespace std;
int n,m,s[110],f[15][15],mk,num;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> mk;
	s[1]=mk;
	for (int i = 2;i<=n*m;i++)
		cin >> s[i];
	sort(s+1,s+n*m+1);
	for (int i = n*m;i>=1;i--)
	{
		if (s[i]==mk) num = n*m - i + 1;
	}
	int ans = (num-1)/m+1;
	cout << ans << " ";
	if (ans%2==1)
	{
		cout << num - (ans-1)*n;
	}
	else
	{
		cout << ans* n - num + 1;
	}
	return 0;
 }
