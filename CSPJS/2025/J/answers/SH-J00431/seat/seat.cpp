#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105]={0};
int c,r;
int rs;
void seat(int x,int y,int l)
{
	if(a[l]==rs)
	{
		c=y;
		r=x;
		return;
	}
	l--;
	if(((x==1)&&(y%2==0))||((x==n)&&(y%2==1)))
	{
		seat(x,y+1,l);
	}
	else if(y%2==1)
	{
		seat(x+1,y,l);
	}
	else if(y%2==0)
	{
		seat(x-1,y,l);
	}
	else
	{
		rs+=0;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=0;i<t;i++)
	{
		cin>>a[i];
		if(i==0)
		{
			rs=a[i];
		}
	 }
	sort(a,a+t);
	seat(1,1,t-1);
	cout<<c<<" "<<r;
	return 0;
 } 
