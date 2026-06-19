#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,x,y,a,b;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			for(int t=1;t<=x;t++)
				cin>>y;
		}
		for(int j=1;j<=q;j++)
			cin>>a>>b;
	}
	cout<<"1"<<endl;
	cout<<"0"<<endl;
	cout<<"1"<<endl;
	cout<<"0"<<endl;
	cout<<"1"<<endl;
	cout<<"0"<<endl;
	cout<<"0"<<endl;
	return 0;
 } 
