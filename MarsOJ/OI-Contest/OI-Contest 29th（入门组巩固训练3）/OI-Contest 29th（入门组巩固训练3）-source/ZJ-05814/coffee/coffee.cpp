#include<bits/stdc++.h>
using namespace std;
char s[9][6];
int main()
{
	int t,n,m,sum=0,k,p=0,a;
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=8;j++)
		{
			for(int k=1;k<=5;k++)
				cin>>s[j][k];
		}
		cin>>n>>m;
	}
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(s[i][j]=='math') sum++;
		}
	}
	if(n%7==0) cout<<(n/7)*sum;
	else
	{
		k=n%7;
		for(int i=1;i<=k;i++)
		{
			if((m-1+i)==6||(m-1+i)==7) p=0;
			else
			{
				for(int j=1;j<=8;j++)
				{
					a=(m-1+i)%7;
					if(s[j][a]=='math') p++;
				}
			}
		}
		cout<<p+sum;
	}
	return 0;
 } 
