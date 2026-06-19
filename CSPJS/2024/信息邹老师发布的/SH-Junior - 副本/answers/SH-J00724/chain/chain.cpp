#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[10001][20001],s[10001][20001]={0},r,c,tt;
bool f1(int ps,int nm)
{
	for(int i=1;i<=l[ps][0];i++)
	{
		if(nm==s[ps][i]&&l[ps][i]==1)
		{
			return true;
		}
	}
	return false;
}
bool f(int rd,int ps,int nm)
{
	bool sum=false;
	if(rd==1)
	{
		return f1(ps,nm);
	}
	for(int j=1;j<=l[ps][0];j++)
	{
		if(s[ps][j]==nm)
		{
			for(int i=j-1;i>=j-k+1;i--)
			{
				for(int ii=1;ii<=n;ii++)
				{
					if(ii==ps)
					{
						continue;
					}
					sum=sum||f(rd-1,ii,s[ps][i]);
					if(sum)
					{
						return true;
					}
				} 
			}
		}
	}
	return false;
}
bool finall(int rd,int nm)
{
	bool sum0=false;
	for(int iii=1;iii<=n;iii++)
	{
		sum0=sum0||f(rd,iii,nm);
	}
	return sum0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int ll=1;ll<=t;ll++)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i][0];
			tt=-10000000;
			for(int j=1;j<=l[i][0];j++)
			{
				cin>>s[i][j];
				if(j-tt<k)
				{
					l[i][j]=1;
				}
				else
				{
					l[i][j]=0;
				}
				if(s[i][j]==1)
				{
					tt=j;
				}
			}
		}
		for(int lll=1;lll<=q;lll++)
		{
			cin>>r>>c;
			if(r==1)
			{
				tt=0;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=l[i][0];j++)
					{
						if(s[i][j]==c&&l[i][j]==1)
						{
							tt++;
							break;
						}
					}
					if(tt>0)
					{
						break;
					}
				}
				if(tt>0)
				{
					cout<<1<<endl;
				}
				else
				{
					cout<<0<<endl;
				}
				continue;
			}
			if(finall(r,c))
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
