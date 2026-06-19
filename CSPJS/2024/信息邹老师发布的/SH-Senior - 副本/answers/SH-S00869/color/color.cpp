#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+5;
int a[N],c[N];
int stkred[N],stkblue[N],topred,topblue;
int T,n;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		long long ans=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}
		if(n<=64)
		{
			long long cnt=0;
			long long sign=0;
			for(;sign<1<<n;sign++)
			{
				int lastred=0,lastblue=0;
				cnt=0;
				for(int j=1;j<=n;j++)
				{
					if(1<<(j-1)&sign)//red
					{
						if(lastred==a[j]) cnt+=a[j];
						else lastred=a[j];
					}
					else //blue
					{
						if(lastblue==a[j]) cnt+=a[j];
						else lastblue=a[j];
					}
				}
				ans=max(ans,cnt);
			}
			printf("%d\n",ans);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
