#include<bits/stdc++.h>
using namespace std;
int arr[100005],visited[100005];
long long num[100005];
int main()
{
		freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	memset(num,0x00,sizeof(num));
	int n,i,j,ans=0,_max=0,_min=INT_MAX,s1=0,s2=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&arr[i]);
		_max=max(_max,arr[i]);
		_min=min(_min,arr[i]);
		++num[arr[i]];
	}
	if(_max<=2)
	{
		for(i=1;i<=n;++i)
		{
			if(arr[i]==1)
			{
				++s1;
			}
			else if(arr[i]==2)
			{
				++s2;
			}
		}
		ans=min(s1,s2);
		printf("%d",n-ans);
	}
	else if(n<=10)
	{
		sort(arr+1,arr+1+n);
		for(i=1;i<n;++i)
		{
			for(j=i+1;j<=n;++j)
			{
				if(visited[j])
				{
					continue;
				}
				if(arr[j]>arr[i])
				{
					visited[j]=1;
					++ans;
					break;
				}
			}
		}
		printf("%d",n-ans);
	}
	else
	{
		for(i=_min+1;i<=_max;++i)
		{
			if(num[i]==0)
			{
				num[i]=num[i-1];
				num[i-1]=0;
				continue;
			}
			else if(num[i-1]>=num[i])
			{
				num[i]+=(num[i-1]-num[i]);
			}
			num[i-1]=0;
		}
		printf("%lld",num[_max]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
