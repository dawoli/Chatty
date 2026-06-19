#include<bits/stdc++.h>
using namespace std;
struct node
{
	int w,id;
}a[101];
bool cmp(node x,node y)
{
	return x.w>y.w;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int tmp=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			tmp=i;
			break;
		}
	}
	int c=(int)ceil(tmp*1.0/n),r;
	if(c%2)
	{
		r=tmp%n;
		if(r==0)
		{
			r=n;
		}
	}
	else
	{
		r=tmp%n;
		if(r==0)
		{
			r=n;
		}
		r=(n+1)-r;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
