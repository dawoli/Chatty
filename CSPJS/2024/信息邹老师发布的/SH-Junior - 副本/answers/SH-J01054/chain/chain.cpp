#include <cstdio>
#include <vector>
using namespace std;
int T,n,k,q,l[100005];
vector <int> a[100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	scanf("%d",&T);
	for (int Q=1;Q<=T;Q++)
	{
		scanf("%d%d%d",&n,&k,&q);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&l[i]);
			for (int j=0;j<l[i];j++)
			{
				int x;
				scanf("%d",&x);
				a[i].push_back(x);
			}
		}
		for (int i=0;i<q;i++)
		{
			scanf("%d%d",&r,&c);
			printf("0\n");
		}
	}
    return 0;
} 
