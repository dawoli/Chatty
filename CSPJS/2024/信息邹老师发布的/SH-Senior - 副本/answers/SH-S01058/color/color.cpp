#include <cstdio>
#include <cstring>
const int N=200100;
long long a[N];
int b[N];
long long ans=0;
int n;
void dfs(int x)
{
	if(x==n+1)
	{
		long long now_ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(b[i]==b[j])
				{
					now_ans+=((a[i]==a[j]) ? a[i] : 0);
					break;
				}
			}
		}
		if(ans<now_ans)
		{
			ans=now_ans;
		}
		return ;
	}
	b[x]=0;
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		dfs(1);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
