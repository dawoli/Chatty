#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int v;
	bool f;	
}a[5000];
bool cmp(node x,node y)
{
	return x.v>y.v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].v;
		if(i==1) a[i].f=1;
		else a[i].f=0;
	}
	sort(a+1,a+n*m+1,cmp);
	int cur=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cur++;
				if(a[cur].f==1)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				cur++;
				if(a[cur].f==1)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
