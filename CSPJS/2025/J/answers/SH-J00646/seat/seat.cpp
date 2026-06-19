#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
struct student{int num,pos;}a[102];
bool cmp(student x,student y)
{
	return x.num>y.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].pos=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].pos==1)
		{
			int x=(i-1)/n;
			printf("%d ",x+1);
			if(x%2==0)
			{
				if(i%n!=0) printf("%d",i%n);
				else printf("%d",n);
			}
			else 
			{
				if(i%n!=0) printf("%d",n-i%n+1);
				else printf("1");
			}
			return 0;
		}
	}
	return 0;
}
