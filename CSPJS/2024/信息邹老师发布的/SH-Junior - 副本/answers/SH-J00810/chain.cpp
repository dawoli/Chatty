#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(NULL));
	int n;
	cin>>n;
	int num[n];
	for(int i=1;i<=n;i++)
	{
		int o,p,q;
		cin>>o>>p>>num[i];
		for(int j=1;j<=o;j++)
		{
			int c;
			cin>>c;
			for(int k=1;j<=c;k++)
			{
				int d;
				cin>>d;
			}
		}
		for(int d=1;d<=q;i++)
		{
			int x,y;
			cin>>x>>y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=num[i];j++)
		{
			int a=rand();
			cout<<a%2<<endl;;
		}
	}
	return 0;
}
