#include<iostream>
#include<cstdio>
#include<iomanip>
#include<fstream> 
using namespace std;
int a[10001][20001]={0};
int l[10001]={0};
int n,q,k;
bool whethercan(int s,int mygoal,int wherecomes)
{
	for(int i=1;i<=n;i++)
	{
		if(i!=wherecomes)
		{
			for(int j=1;j<=l[i];j++)
			{
				if(a[i][j]==mygoal)
				{
					if(s==1)
					{
						for(int m=j-1;m>=1&&j-m<=k-1;m--)
						{
							if(a[i][m]==1)return true;		
						}
					}
					else
					{
						for(int m=j-1;m>=1&&j-m<=k-1;m--)
						{
							if(whethercan(s-1,a[i][m],i)==true)
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int h=1;h<=t;h++)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=q;i++)
		{
			int theperson,thegoal;
			cin>>theperson>>thegoal;
			if(whethercan(theperson,thegoal,0)==true)
			{
				cout<<1<<endl;
			}
			else cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
