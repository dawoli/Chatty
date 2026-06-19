#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,y=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<n*m;i++)
	{
		scanf("%d",&x);
		if(x>a)
		{
			y++;
		}
	}
	if(n==1)
	{
		printf("%d 1",y+1);
		return 0;
	}
	for(int i=1,j=2,k=1,f=1;;k++)
	{
		if(k==y)
		{
			printf("%d %d",i,j);
			return 0;
		}
		if((j==1||j==n)&&f)
		{
			i++;
			f=0;
		}
		else
		{
			if(i%2==0)
			{
				j--;
			}
			else
			{
				j++;
			}
			f=1;
		}
	}
	return 0;
} 
