#include <bits/stdc++.h>
using namespace std;
int n,m,target;
int a[100000];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>target;
	a[0]=target;
	for (int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	int k=0;
	for (k=0;k<n*m;k++)
	{
		if (a[k]==target)
		{
			break;
		}
	}
	int x=k/n+1,y=k%n+1;
	if (x%2==0)
	{
		y=(n+1)-y;
	}
	cout<<x<<" "<<y;

	return 0;
}
