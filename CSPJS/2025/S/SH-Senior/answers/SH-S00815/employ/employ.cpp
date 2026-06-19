#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
char diff[505];
int pat[505];
int cnt;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,flag=1;
	scanf("%d %d",&n,&m);
	scanf("%s",diff+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pat[i]);
		if(pat[i]==0)
			cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		if(diff[i]!='1')
			flag=0; 
	}
	if(flag==1)
	{
		long long ret=1;
		if((n-cnt)<m)
			printf("0\n");
		else
		{
			for(int i=0;i<m;i++)
			{
				ret*=(n-cnt-i);
				ret%=MOD;
			}
			for(int i=0;i<(n-m);i++)
			{
				ret*=(n-m-i);
				ret%=MOD;
			}
			printf("%lld\n",ret);
		}
	}
	else
		printf("0");
	return 0;
}
