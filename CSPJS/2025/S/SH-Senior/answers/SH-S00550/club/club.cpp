#include <iostream>
#include <cmath> 
#include <algorithm>
#include <cstring>
using namespace std;
int a[200005][5];
int f[200005];
int ls[200005];
int main()
{
	int t, n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(ls,0,sizeof(ls));
		cin >> n;
		int cnt[5]={0,0,0,0,0};
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2])
			{
				if (a[i][1] >= a[i][3])
				{
					cnt[1]++;
					f[i]=1;
					ls[i]=a[i][1]-max(a[i][2],a[i][3]);
				}
				else
				{
					cnt[3]++;
					f[i]=3;
					ls[i]=a[i][3]-max(a[i][2],a[i][1]);
				}
			}
			else
			{
				if (a[i][2] >= a[i][3])
				{
					cnt[2]++;
					f[i]=2;
					ls[i]=a[i][2]-max(a[i][1],a[i][3]);				
				}
				else
				{
					cnt[3]++;
					f[i]=3;
					ls[i]=a[i][3]-max(a[i][2],a[i][1]);					
				}
			}
		}
		int w = 0;
		if (cnt[1] >= cnt[2])
		{
			if (cnt[1] >= cnt[3])
			{
				w = 1;
			}
			else
			{
				w = 3;
			}
		}
		else
		{
			if (cnt[3] >= cnt[2])
			{
				w = 3;
			}
			else
			{
				w = 2;
			}
		}			
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += max(max(a[i][1],a[i][2]),a[i][3]);
		}
		if (cnt[w] <= n/2)
		{
			cout << ans << '\n';
			continue;
		}	
		int cntt = 0;
		int k[200005];
		for (int i = 1; i <= n; i++)
		{
			if (f[i] == w)
			{
				cntt++;
				k[cntt] = ls[i];
				
			}
		}
		sort(k+1,k+cntt+1);
		int ans2 = 0;
		for(int i = 1; i <= cntt-(n/2); i++)
		{
			ans2+=k[i];
			
		}
		cout << ans-ans2 << '\n';
	}
	return 0;
}
