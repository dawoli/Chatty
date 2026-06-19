#include<bits/stdc++.h>
#define mod 998244553
using namespace std;
int n,a[5005],front_s[5005],cnt=0,_max;
inline bool check(int _len,int _max)
{
	return _len>2*_max;
}
int dfs(int sum,int start,int num)
{
	if(num==0)
	{
		_max=a[start];
		return sum;
	}
	_max=0;
	while(num--)
	{
		for(int i=start+1;i<=n;i++)
		{
			int t=dfs(sum+a[i],i,num);
			if(check(t,_max))
				cnt=(cnt+1)%mod;
		}
	}
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	if(n==3)
	{
		if(check(a[1]+a[2]+a[3],a[3]))
			printf("1\n");
		else
			printf("0\n");
		return 0;
	}
	else if(n==4)
	{
		cnt=0;
		if(check(a[1]+a[2]+a[3],a[3]))
			cnt++;
		if(check(a[1]+a[2]+a[4],a[4]))
			cnt++;
		if(check(a[2]+a[3]+a[4],a[4]))
			cnt++;
		if(check(a[1]+a[2]+a[3]+a[4],a[4]))
			cnt++;
		printf("%d\n",cnt);
		return 0;
	}
	else if(n==5)
	{
		cnt=0;
		if(check(a[1]+a[2]+a[3],a[3]))
			cnt++;
		if(check(a[1]+a[2]+a[4],a[4]))
			cnt++;
		if(check(a[1]+a[2]+a[5],a[5]))
			cnt++;
		if(check(a[1]+a[3]+a[4],a[4]))
			cnt++;
		if(check(a[1]+a[3]+a[5],a[5]))
			cnt++;
		if(check(a[1]+a[4]+a[5],a[5]))
			cnt++;
		if(check(a[2]+a[3]+a[4],a[4]))
			cnt++;
		if(check(a[2]+a[3]+a[5],a[5]))
			cnt++;
		if(check(a[2]+a[4]+a[5],a[5]))
			cnt++;
		if(check(a[3]+a[4]+a[5],a[5]))
			cnt++;
		if(check(a[1]+a[2]+a[3]+a[4],a[4]))
			cnt++;
		if(check(a[1]+a[2]+a[3]+a[5],a[5]))
			cnt++;
		if(check(a[1]+a[2]+a[4]+a[5],a[5]))
			cnt++;
		if(check(a[1]+a[3]+a[4]+a[5],a[5]))
			cnt++;
		if(check(a[2]+a[3]+a[4]+a[5],a[5]))
			cnt++;
		if(check(a[1]+a[2]+a[3]+a[4]+a[5],a[5]))
			cnt++;
		printf("%d\n",cnt);
		return 0;
	}
	for(int i=1;i<=n;i++)
		front_s[i]=front_s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		for(int j=2;j<=n-i;j++)
			dfs(0,i,j);
	printf("%d\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
