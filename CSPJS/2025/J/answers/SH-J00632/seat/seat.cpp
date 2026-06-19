#include<bits/stdc++.h>
using namespace std;
int a[101]={0},n,m,s,im,pm=1,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d",&im);
	for(int i=1;i<n*m;i++)
	{
		scanf("%d",&s);
		a[s]++;
	}
	for(int i=100;i>im;i--)
	{
		pm+=a[i];
	}
//	printf("%d\n",pm);
	x=pm/n+1;
	if(pm%n==0) x--;
	if(x%2==1)
	{
		y=pm%n;
		if(y==0) y=n;
	}
	else
	{
		y=pm%n;
		if(y==0) y==n;
		y=n-y+1;
	}
	printf("%d %d",x,y);
	
	
	return 0;
}
