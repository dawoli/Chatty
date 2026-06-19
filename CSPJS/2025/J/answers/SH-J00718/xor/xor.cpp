#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<int,int> mp;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	mp[0] = 0;
	int p = 0,ans = 0;
	for(int i = 1;i <= n;i++)
	{
		a[i] ^= a[i - 1];
		int need = a[i] ^ k;
		if(mp.find(need) != mp.end() && mp[need] >= p)
		{
			ans++;
			p = i;
		}
		mp[a[i]] = i;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
