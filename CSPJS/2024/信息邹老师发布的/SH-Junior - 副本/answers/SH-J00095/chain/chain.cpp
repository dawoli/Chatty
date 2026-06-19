#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
	int code,x;
}a[200010];

int l[100010],s[100010];
bool have[200010];

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,q,cnt = 0;
		scanf("%d%d%d",&n,&k,&q);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&l[i]);
			s[i] = s[i - 1] + l[i];
			for(int j = 1;j <= l[i];j++)
			{
				scanf("%d",&a[++cnt].x);
				a[cnt].code = i;
				if(l[i] > 1) have[a[cnt].x] = true;
			}
		}
		for(int i = 1;i <= q;i++)
		{
			int r,c;
			scanf("%d%d",&r,&c);
			if(have[c] == false)
			{
				printf("0\n");
				continue;
			}
			printf("1\n");
		}
	} 
	return 0;
}
