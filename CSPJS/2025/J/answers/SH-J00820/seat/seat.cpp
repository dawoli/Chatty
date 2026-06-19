#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],rs,rr;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if (i==1)
		{
			rs=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==rs) rr=i;
	}
	int x=(rr-1)/n+1,y=(rr-1)%n+1;
	if (x%2==1)
	{
		printf("%d %d",x,y);
	}
	else
	{
		printf("%d %d",x,n-y+1);
	}
}
