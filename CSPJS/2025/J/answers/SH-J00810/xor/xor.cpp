#include<bits/stdc++.h>
using namespace std;
int arr[500005];
int cnt[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flagA=1,flagB=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		cnt[arr[i]]++;
		if(arr[i]!=1)
		{
			flagA=0;
		}
		if(arr[i]!=1&&arr[i]!=0)
		{
			flagB=0;
		}
	}
	if(flagA)
	{
		printf("%d\n",n/2);
	}
	else if(flagB)
	{
		if(k==0)
		{
			int ans=cnt[0];
			for(int i=1;i<=n;i++)
			{
				if(arr[i]==1&&arr[i-1]==1)
				{
					ans++;
					i++; 
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			printf("%d\n",cnt[1]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
