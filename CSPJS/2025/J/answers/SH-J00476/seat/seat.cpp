#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int c=n*m;
	int a[c];
	for(int i=0;i<c;i++)
	{
		cin >> a[i];
	}
	int b=a[0];
	sort(a,a+c);
	int x,y;
	for(int i=0;i<c;i++)
	{
		if(a[i]==b)
		{
			x=(i+1)%n,y=(i+1)/n+1;
			if(x==0)
			{
				x=i+1;
				y--;
			}
			if(x%2==0)y=n-y+1;
		}
	}
	printf("%d %d",x,y);
	fclose(stdin);
	fclose(stdout);
}
