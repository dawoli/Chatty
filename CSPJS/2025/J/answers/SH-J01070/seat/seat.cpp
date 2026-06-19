#include <bits/stdc++.h>
using namespace std;
int a[15][15];
struct node
{
	int id,va;
} ma[105];
bool cmp(node x,node y)
{
	return x.va>y.va;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)	{cin>>ma[i].va;ma[i].id=i;}
	sort(ma+1,ma+n*m+1,cmp);
	int d=-1;
	for (int i=1;i<=n*m;i++)
	{
		if (ma[i].id==1)
		{
			d=i;
			break;
		}
	}
	int p=(d-1)/n+1;
	cout<<p<<" ";
	if (p%2==1)
	{
		cout<<(d-1)%n+1<<endl;
	}
	else
	{
		cout<<n-(d-1)%n<<endl;
	}
	return 0;
}

