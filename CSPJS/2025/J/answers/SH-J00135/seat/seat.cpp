#include<bits/stdc++.h>
using namespace std;
int a[11][11]={};
int x[105]={};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int Jeff=n*m;
	for(int i=1;i<=Jeff;i++)
	{
		cin>>x[i];
	}
	int f=x[1];
	sort(x+1,x+Jeff+1,cmp);
	int o=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[o]==f)
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			o++;
		}
	}
	return 0;
}
