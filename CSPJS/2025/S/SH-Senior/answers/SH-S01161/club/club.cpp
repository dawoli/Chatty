#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		int n;
		scanf("%d",&n);
		int a[n+1][2],m[n],sum=0;
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&m[0]);
		for(int i=0;i<n;i++)
		{
			sum+=a[i][1];
			m[i]=a[i][1]-a[i][0];
		}
		sort(m,m+n);
		for(n=n/2-1;n>=0;n--)
			sum-=m[n];
		printf("%d\n",sum);
	}
	return 0;
}
