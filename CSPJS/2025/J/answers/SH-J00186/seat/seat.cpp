#include<bits/stdc++.h>
using namespace std;
int a[10000],m,n,f,cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++)
	{
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+c+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				cnt++;
				if(f==a[cnt])
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		else if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				cnt++;
				if(f==a[cnt])
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
