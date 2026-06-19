#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(stdin,"r",seat.in);
	freopen(stdout,"w",seat.out);
	int m,n;
	scanf("%d%d",&n,&m);
	int a[m][n],k=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]>a[1][1])
				k++;
		}
	}
	if(k%n==0)
	{
		if(((k/n)%2==1))
			printf("%d %d",k/n,n);
		if((k/n)%2==0)
			printf("%d %d",k/n,1);
	}
	else if(k%n!=0)
	{
		if(((k-k%n+n)/n)%2==1)
			printf("%d %d",(k-k%n+n)/n,k%n);
		if(((k-k%n+n)/n)%2==0)
			printf("%d %d",(k-k%n+n)/n,n+1-k%n);
	}
	return 0;
}
