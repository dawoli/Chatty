#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val,rk,idx;
}a[110];
bool cmp1(node a,node b)
{
	return a.val>b.val;
}
bool cmp2(node a,node b)
{
	return a.rk<b.rk;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i].val;
		a[i].rk=i;
	}
	sort(a+1,a+n*m+1,cmp1);
	for (int i=1;i<=n*m;i++)
	{
		a[i].idx=i;
	}
	sort(a+1,a+n*m+1,cmp2);
	int id=a[1].idx;
	int c=(id-1)/m+1;
	int r=(id-1)%m+1;
	if (c%2==0)r=m+1-r; 
	cout<<c<<' '<<r<<endl;
}
