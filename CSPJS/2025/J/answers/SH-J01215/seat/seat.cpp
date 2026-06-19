#include<bits/stdc++.h>
using namespace std;
int a[110];
bool rule(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,rule);
	for(int i=1;i<=n*m;i++)
	{
		if(k==a[i])
		{
			k=i;
			break;
		}
	}
	int c,r;
	c=ceil(k/(n*1.0));
	if(c%2==1)
		r=k%n;
	else
		r=n-k%n+1;
	if(r==0)
		r=n;
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
