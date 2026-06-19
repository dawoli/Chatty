#include <bits/stdc++.h>
using namespace std;
int a[110101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cnt)
		{
			cnt=n*m-i+1;
			break;
		}
	}
	int r=1,c=1;
	bool flag=false;
	for(int i=2;i<=cnt;i++)
	{
		if(r==n&&flag==false)
		{
			c++;
			flag=true;
		}
		else if(r==1&&flag==true)
		{
			c++;
			flag=false;
		}
		else if(flag==false)
		{
			r++;
		}
		else
		{
			r--;
		}
	}
	cout<<c<<" "<<r;
}
