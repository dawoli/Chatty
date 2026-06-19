#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)num=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++)
	{
		if(num==a[i])
		pos=i;
	}
	int x1=(pos-1)/n+1,y1;
	if(x1%2==1)
	{
		y1=(pos-1)%n+1;
	}
	else
	{
		y1=n-(pos-1)%n;
	}
	cout<<x1<<" "<<y1<<endl;
	return 0;
}
