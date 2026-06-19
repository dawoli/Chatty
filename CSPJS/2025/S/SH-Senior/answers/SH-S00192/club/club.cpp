#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N][3],n,ans = -1,f[205][105][105],maxn = -1;

void dfs(int step,int satis,int cnt1,int cnt2,int cnt3)
{
	if(cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return ;
	if(step > n)
	{
		ans = max(ans,satis);
//		printf("%d %d %d %d\n",cnt1,cnt2,cnt3,satis);
		return ;
	}
	dfs(step + 1,satis + a[step][0],cnt1 + 1,cnt2,cnt3);
	dfs(step + 1,satis + a[step][1],cnt1,cnt2 + 1,cnt3);
	dfs(step + 1,satis + a[step][2],cnt1,cnt2,cnt3 + 1);
}

void Solve()
{
	cin >> n;
	ans = 0;
	memset(a,0,sizeof a);
	for(int i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
//	dfs(1,0,0,0,0);
//	cout << ans << endl;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		Solve();
//		cin >> n;
//		memset(a,0,sizeof a);
//		for(int i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
		memset(f,0,sizeof f);
		maxn = -1;
		f[1][1][0] = a[1][0];
		f[1][0][1] = a[1][1];
		f[1][0][0] = a[1][2];
		for(int i = 2;i <= n;i++)
		{
			for(int j = 0;j <= i && j <= n / 2;j++)
			{
				for(int k = 0;k <= i && k <= n / 2;k++)
				{
					if(j + k > i) continue;
					if(i - j - k > n / 2) continue;
					f[i][j][k] = f[i - 1][j][k] + a[i][2];
//					printf("f[%d][%d][%d] = %d\n",i,j,k,f[i][j][k]);
					if(j >= 1) f[i][j][k] = max(f[i][j][k],f[i - 1][j - 1][k] + a[i][0]);
//					printf("f[%d][%d][%d] = %d\n",i,j,k,f[i][j][k]);
					if(k >= 1) f[i][j][k] = max(f[i][j][k],f[i - 1][j][k - 1] + a[i][1]);
//					printf("f[%d][%d][%d] = %d\n",i,j,k,f[i][j][k]);
					if(i == n && j <= n / 2 && k <= n / 2 && n - k - j <= n / 2)
					{
			// 			printf("f[%d][%d][%d] = %d\n",i,j,k,f[i][j][k]);
						maxn = max(maxn,f[i][j][k]);
						}
				}
			}
		}
		cout << maxn << endl;
	}
	return 0;
}
 
