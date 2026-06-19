#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,R;
struct node
{
	int s,num;
}a[205];
bool cmp(node a,node b){return a.s>b.s;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].s);
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].num==1)
		{
			R=i;
			break;
		}
	}
	c=R/(2*n)*2;
	R-=c*n;
	if(R==0)
	{
		printf("%d 1\n",c);
		return 0;
	}
	if(R%n==0)
	{
		printf("%d %d\n",c+1,n);
		return 0;
	}
	if(R<=n)
	{
		c++;
		r=R;
	}
	else
	{
		c+=2;
		R-=n;
		r=n-R+1;
	}
	printf("%d %d\n",c,r);
	return 0;
}
