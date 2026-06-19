#include<bits/stdc++.h>
using namespace std;
int n,m;
struct person
{
	int num, point;
}a[101];
bool Cmp(person x,person y)
{
	return x.point>y.point;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		a[i].num=i;
		cin>>a[i].point;
	}
	sort(a+1,a+m*n,Cmp);
	int p=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[p].num==1)
			{
				cout<<i<<" ";
				if(i%2==1)cout<<j;
				else cout<<n+1-j;
				cout<<endl;
				return 0;
			}
			p++;
		}
	}
}
