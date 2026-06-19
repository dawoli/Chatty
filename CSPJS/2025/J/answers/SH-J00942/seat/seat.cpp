#include<bits/stdc++.h>
using namespace std;
long long n,m,xm;
long long a[105],b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>xm;
	a[1]=xm;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	long long cnt=0;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==xm)
		{
			cnt=n*m-i+1;
			break;
		}
	}
	long long hang=cnt%n;
	long long lie=cnt/n+1;
	if(hang==0)
	{
		lie=cnt/n;
	}
	if(hang==0)
	{
		hang+=n;
	}
	if(lie%2!=0)
	{
		cout<<lie<<" "<<hang<<endl;
	}
	else
	{
		cout<<lie<<" "<<n-hang+1<<endl;
	}
	return 0;
}
