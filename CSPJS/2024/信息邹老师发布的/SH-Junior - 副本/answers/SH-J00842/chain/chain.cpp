#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,num[1010][1010],l[1010],r,c,ret,flag;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
				cin>>num[i][j];
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r>>c;
			flag=0;
			for(int j=1;j<=n;j++)
			{
				ret=0;
				for(int p=1;p<=l[i];p++)
				{
					if(num[j][p]==1)
						ret=p;
					if(ret&&num[j][p]==c&&(p-ret+1)<=k)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					cout<<1<<endl;
					break;
				}
			}
			if(flag==0)
				cout<<0<<endl;
		}
	}
	return 0;
}
