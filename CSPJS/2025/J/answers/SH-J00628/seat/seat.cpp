#include<iostream>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1,x,c,r;
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++)
	{
		int y;
		cin>>y;
		if(x<y)
		{
			cnt++;
		}
	}
	c=(cnt+n-1)/n;
	if(c%2==1)
	{
		r=(cnt-1)%n+1;
	}
	else
	{
		r=(cnt-1)%n+1;
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
