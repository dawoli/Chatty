#include<bits/stdc++.h>
using namespace std;
int a[1005],n=0,m=0,xm=0,s=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	xm=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
		if(a[i]==xm)
		{
			s=n*m-i+1;
			break;
		}
	
	if(s%n==0)
	{
		printf("%d ",s/n);
		if((s/n)%2==1)printf("%d",n);
		else printf("1");
	}
	else
	{
		printf("%d ",s/n+1);
		if((s/n)%2==1)printf("%d",n-(s%n)+1);
		else printf("%d",s%n);
	}
	return 0;
}
