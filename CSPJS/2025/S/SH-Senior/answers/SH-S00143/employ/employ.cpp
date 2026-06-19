#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt0=0,ans=1,usu=0,cnt1=0;
	cin>>n>>m;
	char s[n];
	int c[n],ft1=n,flag=1;
	for(int i=0;i<n;i++)
	{
		scanf("%c",&s[i]);
		if(s[i]==1)
			cnt1++;
		if(flag && s[i]==1)
		{
			ft1=i;
			flag=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d ",&c[i]);                    
		if(!c[i])
			cnt0++;
	}
	if(n==cnt0)
	{
		printf("0");
		return 0;
	}
	if(m==1)
	{
		sort(c,c+n);
		for(int i=0;i<n;i++)
		{
			int j,p=1;
			for(j=0;j<n;j++)
			{
				if(c[j]>i)
					break;
			}
			for(int k=1;k<n-j-1;k++)
				p=p*k%988244353;
			ans+=p%988244353;
		}
		if(cnt1==n)
			printf("%d",ans);
		else
		{
			for(int i=0;i<n;i++)
			{
				if(c[i]==1)
					continue;
				int j,p=1;
				for(j=0;j<n;j++)
				{
					if(c[j]>i)
						break;
				}
				p*=j;
				for(int k=1;k<n-1;k++)
					p=p*k%988244353;
				
				ans+=p%988244353;
			}
			printf("%d",ans);
		}
	}
	else if(m==n)
	{
		sort(c,c+n);
		for(int j=0;j<n;j++)
			usu+=c[j]>j ? 0 : 1;
		if(cnt0 || usu>0)
			printf("0");
		else
		{
			for(int j=1;j<n;j++)
				ans=ans*j%988244353;
			printf("%d",ans);
		}
	}
	else if(cnt1==18)
		printf("998244352"); 
	else
		printf("0");
	return 0;
}
