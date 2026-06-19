#include<bits/stdc++.h>
using namespace std;
int arr[500005],sum[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,j,p,ans,cnt;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&arr[i]);
		sum[i]=sum[i-1]^arr[i];
	}
	if(n<=10000)
	{
		f[0]=0;
		for(i=1;i<=n;++i)
		{
			f[i]=f[i-1];
			for(j=0;j<i;++j)
				if((sum[i]^sum[j])==k)
					f[i]=max(f[i],f[j]+1);
		}
		printf("%d",f[n]);
	}
	else
	{
		if(k<=1)
		{
			ans=0;
			p=arr[1];
			cnt=1;
			for(i=2;i<=n;++i)
			{
				if(arr[i]==p)
					++cnt;
				else
				{
					if(p==k)
						ans+=cnt;
					else
						ans+=cnt/2;
					p=arr[i];
					cnt=1;
				}
			}
			if(p==k)
				ans+=cnt;
			else
				ans+=cnt/2;
			printf("%d",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
