#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num,pl;
}a[10005];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].pl=p;
		p++;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++)
	{
//		cout<<i<<" "<<a[i].num<<" "<<a[i].pl<<endl;
		if(a[i].pl==1)
		{
			cout<<x<<" "<<y<<endl;
			break;
		}
		else
		{
			if(x%2==1)
			{
				if(y==n)
				{
					x++;
				}
				else
				{
					y++;
				}
			}
			else
			{
				if(y==1)
				{
					x++;
				}
				else
				{
					y--;
				}
			}
		}
	}
	return 0;
}
