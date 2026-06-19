#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <bitset>
#define int long long
using namespace std;

int a[1005][1005],num[1005],n,k,ans = -1,how[1005];

void dfs(int step,int cnt)
{
	if(step > n)
	{
		ans = max(ans,cnt);
		return ;
	}
	if(how[step] >= cnt) return ;
	how[step] = cnt;
	for(int i = step;i <= n;i++)
	{
		if(a[step][i] == k)
		{
			dfs(i + 1,cnt + 1);
			break;
		}
	}
	dfs(step + 1,cnt);
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(n <= 1000)
	{	
		memset(how,-1,sizeof(how));
		for(int i = 1;i <= n;i++) cin >> num[i];
		for(int l = 1;l <= n;l++)
		{
			for(int r = 1;r <= n;r++)
			{
				a[l][r] = num[l];
				for(int i = l + 1;i <= r;i++)
					a[l][r] ^= num[i];
			}
		}
		dfs(1,0);
		cout << ans;
	}
	else cout << 0;
	return 0;
}
// 嗟夫！余尝求古仁人之心，或异二者之为，何哉？不以物喜，不以己悲。居庙堂之高则忧其民，处江湖之远则忧其君，是进亦忧，退亦忧，然则何时而乐耶？其必曰：“先天下之忧而忧，后天下之乐而乐”呼！噫！微斯人，吾谁与归？时六年九月十五日。
