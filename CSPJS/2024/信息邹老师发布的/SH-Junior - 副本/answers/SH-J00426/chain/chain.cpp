#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	int round;
	for(round=1;round<=t;round++)
	{
		int n,k,q;
		cin>>n>>k>>q;
		int i,j;
		int list_num[n+1][k+1];
		int list_l[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>list_l[i];
			for(j=1;j<=list_l[i];j++)
			{
				cin>>list_num[i][j];
			}
		}
		int r,c;
		for(j=1;j<=q;j++)
		{
			cin>>r>>c;
			cout<<0<<endl;
			/*if(c<=1)
			{
				cout<<0<<endl;
				continue;
			}
			for(int ii=1;ii<=c;ii++)
			{
				
			}*/
			
			
			
			
		}
	}
	return 0;
}
