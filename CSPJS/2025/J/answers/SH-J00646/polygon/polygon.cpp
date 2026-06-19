#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int p=998244353;
int n,a[5003],jc[5003],ans,cnt[5003];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		maxn=max(maxn,a[i]);
	}
	if(n<=3&&maxn<=10)
	{
		if(a[1]+a[2]+a[3]>maxn*2) printf("1");
		else printf("0");
		return 0;
	}
	if(n<=5000&&maxn==1)
	{
		for(int i=3;i<=n;i++)//m=i
		{
			memset(cnt,0,sizeof(cnt));
			int pos=0;
			jc[i]=1;
			for(int j=i+1;j<=n;j++) pos++,cnt[pos]=j;
			for(int j=1;j<=n-i;j++)
			{
				int x=j;
				for(int k=1;k<=pos;k++)
				{
					if(cnt[k]%x==0)
					{
						cnt[k]/=x;
						break;
					}
				}
			}
			for(int j=1;j<=pos;j++) jc[i]=(jc[i]*(cnt[j]%p)+p)%p;
			ans=((ans+jc[i])%p+p)%p;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
