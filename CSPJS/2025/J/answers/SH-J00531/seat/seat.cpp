#include <bits/stdc++.h> 
using namespace std;
int a[105],ans,b,c,r,m,n,R;
double d,e;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)cin>>a[i];
	R=a[1];
	sort(a,a+m*n+1);
	for(int i=1;i<=m*n;i++)if(a[i]==R)b=m*n-i+1;
	d=b;
	e=n;
	c=ceil(d/e);
	r=b%n;
	if(r==0)r=n;
	if(c%2==0)r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
