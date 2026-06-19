#include<bits/stdc++.h>
using namespace std;

int cnt1,cnt2,cnt3;
long long ans;
int p1[100010];
int p2[100010];
int p3[100010];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cnt1 = cnt2 = cnt3 = 0;
		ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			if(a >= b && a >= c)p1[++cnt1] = a - max(b,c),ans += a;
			else if(b >= a && b >= c)p2[++cnt2] = b - max(a,c),ans += b;
			else p3[++cnt3] = c - max(a,b),ans += c;
		}
		if(cnt1 > n / 2)
		{
			sort(p1 + 1,p1 + cnt1 + 1);
			for(int i = 1;i <= cnt1 - n / 2;i++)
				ans -= p1[i];
		}
		if(cnt2 > n / 2)
		{
			sort(p2 + 1,p2 + cnt2 + 1);
			for(int i = 1;i <= cnt2 - n / 2;i++)
				ans -= p2[i];
		}
		if(cnt3 > n / 2)
		{
			sort(p3 + 1,p3 + cnt3 + 1);
			for(int i = 1;i <= cnt3 - n / 2;i++)
				ans -= p3[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
