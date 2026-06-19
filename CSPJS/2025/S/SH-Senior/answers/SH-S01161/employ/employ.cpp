#include<bits/stdc++.h>
using namespace std;
long long f(int n)
{
	if(n==1)
		return 1;
	return n*f(n-1)%998244353; 
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0;
	scanf("%d%d",&n,&m);
	char c[1000]={};
	scanf("\n %s",c);
	for(int i=0;i<n;i++)
	{
		if(c[i]=='1')
			sum++;
	}
	if(sum<m)
	{
		printf("0");
		return 0;
	}
	if(sum==n)
		printf("%lld",f(n));
	return 0;
}
