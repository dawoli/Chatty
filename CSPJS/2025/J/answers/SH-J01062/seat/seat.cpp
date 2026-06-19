#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,ans,b,c,x,y,j;
	cin>>n>>m;
	int a[n*m+10];
	for(i=1;i<=n*m;i++)cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
	 	if(ans==a[i])
	   {
		    b=i;
		    break;
	   }
	}
	j=0;
	for(x=1;x<=n;x++)
	{
		if(x%2!=0)
		{
			for(y=1;y<=m;y++)
			{
				j++;
				if(j==b)
				{
					cout<<x<<" "<<y;
					break;
				}
			}
		}
		else
		{
			for(y=m;y>=1;y--)
			{
				j++; 
				if(j==b)
				{
					cout<<x<<" "<<y;
					break;
				}
			}
		}
		if(j==b)break;
	}
	return 0;
}
