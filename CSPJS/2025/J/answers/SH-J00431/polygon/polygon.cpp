#include<bits/stdc++.h>
using namespace std;
const int Is=998244353;
int n;
int a[5005]={0};
long long cnt=0;

int nmax(int x,int y,int z)
{
	if(x>y&&x>z)
	{
		return x;
	}
	if(y>x&&y>z)
	{
		return y;
	}
	return z;
}

int x=0,y=1,z=1;

bool add()
{
	z++;
	if(z>=n)
	{
		y++;
		if(y>=n)
		{
			x++;
			if(x>=n)
			{
				x=0;
				y=1;
				z=2;
				return false;
			}
			y=x+1;
		}
		z=y+1;
	}
	return true;
}

void result()
{
	while(add()!=0)
	{
		if(a[x]+a[y]+a[z]>2*nmax(x,y,z))
		{
			cnt++;
		}
	}
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	result();
	cout<<(cnt%Is);
	return 0;
 } 
