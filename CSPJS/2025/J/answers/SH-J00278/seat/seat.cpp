#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int s;
	int id;
	bool operator<(const Node& x)
	{
		return s>x.s;
	}
}a[105];
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	int x=0;
	while(a[++x].id!=1);
	int c=(x-1)/n+1;
	int r=(x-1)%n+1;
	if(c%2==0)r=n-r+1; 
	cout<<c<<" "<<r<<endl;
	return 0;
}
