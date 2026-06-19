#include <cstdio>
#include <algorithm>
using namespace std;
const int N=15;
int a[N*N];
int cmp(int a,int b)
{
	return (a>b);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int my_score=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pos=1;
	int ans_c=0,ans_r=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++,pos++)
			{
				if(my_score==a[pos])
				{
					ans_c=j;ans_r=i;
					break;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--,pos++)
			{
				if(my_score==a[pos])
				{
					ans_c=j;ans_r=i;
					break;
				}
			}
		}
		if(ans_c!=0) break;
	}
	printf("%d %d\n",ans_c,ans_r);
	fclose(stdin);fclose(stdout);
	return 0;
}
