#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	int tmp;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int cnt=n*m;
	for(int t=1;t<=n*m;t++)
		for(int i=2;i<n*m;i++)
		{
			if(a[i+1]>a[i])
			{	
				swap(a[i+1],a[i]);
			}
		}
	for(int i=2;i<=n*m;i++)
	{
		if(a[1]>=a[i])
		{
			cnt=i-1;
			break;
		}
	}
	int c,r=-1;
	c=cnt/n;
	if(cnt%n!=0) c++;
	if(c%2==0)
	{
		r=(n-cnt%n+1)%n;
	}
	else
	{
		r=cnt%n;	
	}
	if(r==0) r=n;
	printf("%d %d",c,r);
	return 0;
}
