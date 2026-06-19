#include<iostream>
using namespace std;
int a[1005][2005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	bool p=true;
	cin>>t;
	while(t--)
	{
		int n,k,q;
		cin>>n>>q>>k;
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0];
			for(int j=1;j<=a[i][0];j++)
				cin>>a[i][j];
		}
		while(q--)
		{
			int r,c;
			cin>>r>>c;
			for(int i=0;i<n;i++)
			{
				for(int j=1;j<=a[i][0];j++)
				{
					if(a[i][j]==c)
					{
						for(int l=j-1;l>j-k;l--)
						{
							if(a[i][l]==1)
							{
								cout<<1<<endl;
								p=false;
								break;
							}
						}
						if(!p)
							break;
					}
				}
				if(!p)
					break;
			}
			if(p)
				cout<<0<<endl;
			p=true;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
