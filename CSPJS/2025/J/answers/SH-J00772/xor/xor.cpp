#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0;
long long s[500010];
long long a[500010];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		if(i == 1)
			s[i] = a[i];
		else
			s[i] = s[i - 1] ^ a[i];
	}
	int lst = 0;
	for(int i = lst + 1;i <= n;i ++)
	{
		if(lst == 0 && s[i] == k)
		{
			lst = i;
			ans ++;
			continue;
		}
		for(int j = lst;j < i;j ++)
		{
			//cout << i << " " << j << " " << s[i] << " " << s[j] << " " << (s[i] ^ s[j]) << endl;
			if((s[i] ^ s[j]) == k)
			{
				lst = i;
				ans ++;
				break;
			}			
		}
	}
	
	cout << ans << endl;
	return 0;
}
