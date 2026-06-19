# include <bits/stdc++.h>//ÕâÌâÊ«ÈË£¿£¿£¿ 
using namespace std;
int m,n;
struct node{
	int sco;
	int num;
};
node a[105]={0};
bool cmp(node a,node b)
{
	return a.sco>b.sco;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++)
	{
		cin>>a[i].sco;
		a[i].num=i;
	}
	sort(a+1,a+cnt,cmp);
	int j=0;
	for(int i=1;i<=cnt;i++)
	{
		if(a[i].num==1)
		{
			j=i;
		}
	}
	int x,y;
	x=(j+n-1)/n;
	if(x%2==0)
	{
		y=n-j%n+1;
		if(j%n==0)
		{
			y=1;
		}
	}
	else
	{
		y=j%n;
		if(j%n==0)
		{
			y=n;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
