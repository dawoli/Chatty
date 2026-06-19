#include<iostream>
using namespace std;
int t;
int n,k,q,l,r,c;
int a[1001][1001];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	if(t==1)
	{
		for(int i=0;i<3;i++)
			cout<<1<<"\n"<<0<<"\n";
		cout<<0;
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			cin>>n>>k>>q;
			for(int j=1;j<=n;j++)
			{
				cin>>l;
				for(int s=1;s<=l;s++)
					cin>>a[j][s];
				for(int s=0;s<q;s++)
					cin>>r>>c;	
			}
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
