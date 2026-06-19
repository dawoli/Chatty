#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[510]={0};
int c[510]={0};
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&s[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		ans=ans*i%998224353;
	}
	
	printf("%lld",ans);
	
	return 0;
 } 
