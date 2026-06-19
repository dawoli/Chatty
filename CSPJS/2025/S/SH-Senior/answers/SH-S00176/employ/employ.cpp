#include<bits/stdc++.h>
const int N = 502, MOD = 998244353;
using namespace std;
int n, m, a[N], num[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt = 0;
	for(int i = 0; i < n; i++)
		cnt += (s[i] == '1');
	if(cnt < m)
		cout << 0;
	else if(n > 18)
	{
		long long ans = 1;
		for(int i = 1; i <= n; i++)
			ans = (ans * i) % MOD;
		cout << ans;
	}
	else
	{
		for(int i = 1; i <= n; i++)
			num[i] = i;
		long long ans = 0;
		do
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
			{
				if(i - cnt - 1 >= a[num[i]] || (s[i - 1] == '0'))
					continue;
				cnt++;
			}
			ans = (ans + (cnt >= m)) % MOD;
		}while(next_permutation(num + 1, num + n + 1));
		cout << ans;
	}
	return 0;
	// 既出，得其船，便扶(?)向路，处处志之。及郡下，诣太守，说如此；太守即遣人随其往，寻向所致，遂迷，不复得路。南阳刘子及(?)，高尚士也，闻之，欣然规往，未果，寻病终，后遂无人问津。 
}
