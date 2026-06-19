#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
long long t,ans,z;
long long n,x[100001][10],y[100001]={0,5,4,3,2,1},l[10],m[10],o[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=3;j++)
		{
			l[j]=0;
		}
		z=1;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				scanf("%d",&x[j][k]);
			}
			if(x[j][1]>x[j][2]&&x[j][1]>x[j][3]){
				l[1]++;
				x[j][4]=1;
				ans+=x[j][1];
			}
			else if(x[j][2]>x[j][1]&&x[j][2]>x[j][3]){
				l[2]++;
				x[j][4]=2;
				ans+=x[j][2];
			}
			else if(x[j][3]>x[j][1]&&x[j][3]>x[j][2]){
				l[3]++;
				x[j][4]=3;
				ans+=x[j][3];
			}
			else if(x[j][2]==x[j][1]&&x[j][2]>x[j][3]){
				l[4]++;
				x[j][4]=4;
				ans+=x[j][1];
			}
			else if(x[j][3]==x[j][1]&&x[j][3]>x[j][2]){
				l[5]++;
				x[j][4]=5;
				ans+=x[j][1];
			}
			else if(x[j][2]==x[j][3]&&x[j][2]>x[j][1]){
				l[6]++;
				x[j][4]=6;
				ans+=x[j][2];
			}
			else
			{
				l[7]++;
				x[j][4]=7;
				ans+=x[j][1];
			}
		}
		if(l[1]>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(x[j][4]==1)
				{
					y[z]=x[j][1]-max(x[j][2],x[j][3]);
					z++;
				}
			}
			sort(y,y+z);
			for(int j=1;j<=l[1]-n/2;j++)
			{
				ans=ans-y[j];
			}
		}
		else if(l[2]>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(x[j][4]==2)
				{
					y[z]=x[j][2]-max(x[j][1],x[j][3]);
					z++;
				}
			}
			sort(y,y+z);
			for(int j=1;j<=l[2]-n/2;j++)
			{
				ans=ans-y[j];
			}
		}
		else if(l[3]>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(x[j][4]==3)
				{
					y[z]=x[j][3]-max(x[j][2],x[j][1]);
					z++;
				}
			}
			sort(y,y+z);
			for(int j=1;j<=l[3]-n/2;j++)
			{
				ans=ans-y[j];
			}
		}
		o[i]=ans;
		ans=0;
	}
	for(int i=1;i<=t;i++)
	{
		printf("%d\n",o[i]);
	}
	return 0;
}
