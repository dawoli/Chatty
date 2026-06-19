#include <cstdio>
using namespace std;
int n,k,a[500005],s[500005],j,cnt[1<<20],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for (int i=0;i<=n;i++)
	{
		if (cnt[s[i]^k])
		{
			ans++;
			while (j<i)
			{
				cnt[s[j]]--;
				j++;
			}
			cnt[s[i]]++;
			continue;
		}
		cnt[s[i]]++;
	}
	printf("%d",ans);
	return 0;
}
