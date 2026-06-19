#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mp[200][200],a[200],R,n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1;
	bool mo=1;
	for(int i=n*m;i>=1;i--)
	{
		mp[x][y]=a[i];
		
		if(a[i]==R)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(mo==1)
		{
			x++;
		}
		else
		{
			x--;
		}
		if(x>n)
		{
			x=n;
			mo=0;
			y++;
		}
		else if(x<1)
		{
			x=1;
			mo=1;
			y++;
		}
	}
	return 0;
}

