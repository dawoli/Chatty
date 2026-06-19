#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int c[1000005];
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,n,m,j=0,k;
	scanf("%d %d",&n,&m);
	scanf("%d",&k);
	for(i=0;i<n*m-1;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n*m-1);
	for(i=n*m-2,j=0;i>=0;i--,j++)
	{
		c[j]=a[i];
	}
	for(i=0;i<n*m-1;i++)
	{
		if(k>c[i])
		{
			j=(i+1)/m;
			k=(i+1)%m;
			if(j%2==0)
			{
				printf("%d %d",j+1,k);
			}
			else
			{
				printf("%d %d",j+1,n-k+1);
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
