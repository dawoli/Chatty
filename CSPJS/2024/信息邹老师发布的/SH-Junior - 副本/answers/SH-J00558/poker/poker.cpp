#include<bits/stdc++.h>
using namespace std;
int n,p[5][15],ans,k;
string cp;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cp;
		if(cp[0]=='D')
		{
			k=1;
		}
		else if(cp[0]=='C')
		{
			k=2;
		}
		else if(cp[0]=='H')
		{
			k=3;
		}
		else if(cp[0]=='S')
		{
			k=4;
		}
		if(cp[1]=='A')
		{
			p[k][1]=1;
		}
		else if(cp[1]=='T')
		{
			p[k][10]=1;
		}
		else if(cp[1]=='J')
		{
			p[k][11]=1;
		}
		else if(cp[1]=='Q')
		{
			p[k][12]=1;
		}
		else if(cp[1]=='K')
		{
			p[k][13]=1;
		}
		else
		{
			p[k][cp[1]-'0']=1;
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(p[i][j]!=1)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0; 
} 
