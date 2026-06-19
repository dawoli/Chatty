#include<iostream>
#include<string>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,x,t=1;
	cin>>n>>m;
	for(i=0;i<n*m;i++)
		cin>>a[i];
	x=a[0];
	for(i=1;i<n*m;i++)
	{
		if(a[i]>x)
			t++;
	}
	cout<<t/n+1<<" ";
	if((t/n+1)%2==1)
		cout<<t%n;
	else
		cout<<n-t%n+1;
	return 0;
}
