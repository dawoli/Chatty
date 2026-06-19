#include<iostream>
#include<algorithm>
using namespace std;
struct zw
{
	int cj;
	int id;
};
zw a[110];
int n,m;
bool cmp(zw x,zw y)
{
	return x.cj>y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].cj;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int ans;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			ans=i;
		}
	}
	int r=ans%n;
	int c=ans/n;
	if(r==0)
	{
		if(c%2==0)
		{
			cout<<c<<" "<<1<<endl;
		}
		else
		{
			cout<<c<<" "<<n<<endl;
		}
	}
	else
	{
		c++;
		if(c%2==0)
		{
			cout<<c<<" "<<n-r+1<<endl;
		}
		else
		{
			cout<<c<<" "<<r<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
