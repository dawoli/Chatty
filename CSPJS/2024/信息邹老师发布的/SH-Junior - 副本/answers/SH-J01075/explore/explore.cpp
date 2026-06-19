#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{

	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int t;
	cin>>t;

	for(int u=1;u<=t;u++)
	{

		int ans=0;
		char c[2001][2001];
   		int b[2001][2001];
   		
		ans=0;
		int n,l,k,d;
		cin>>n>>l>>k;
		
		int x[2000],y[2000];


		cin>>x[0]>>y[0]>>d;
		for(int i=1;i<=n;i++)
		{	
			cin>>s;
			for(int j=1;j<=l;j++)
			{
			 c[i][j]=s[j-1];
			}
		}
		b[x[0]][y[0]]=1;
		for(int i=0;i<k;i++)
		{
			if(d==0)
			{
				if(c[x[i]][y[i]+1]=='.') 
				{
					x[i+1]=x[i];
					y[i+1]=y[i]+1;
					if(b[x[i+1]][y[i+1]]==0)
					{
						ans++;
						b[x[i+1]][y[i+1]]++;
					}
				}
				else
				{
					d++;
					x[i+1]=x[i];
					y[i+1]=y[i];
				}
			}
			else if(d==1)
			{
				if(c[x[i]+1][y[i]]=='.') 
				{
					x[i+1]=x[i]+1;
					y[i+1]=y[i];
					if(b[x[i+1]][y[i+1]]==0)
					{
						ans++;
						b[x[i+1]][y[i+1]]++;
					}
					
				}
				else
				{
					d++;
					x[i+1]=x[i];
					y[i+1]=y[i];
				}	
				
			}
			else if(d==2)
			{
				if(c[x[i]][y[i]-1]=='.') 
				{
					x[i+1]=x[i];
					y[i+1]=y[i]-1;
					if(b[x[i+1]][y[i+1]]==0)
					{
						ans++;
						b[x[i+1]][y[i+1]]++;
					}
				}
				else
				{
					d++;
					x[i+1]=x[i];
					y[i+1]=y[i];
				}
				
			}
			else if(d==3)
			{
				if(c[x[i]-1][y[i]]=='.') 
				{
					x[i+1]=x[i]-1;
					y[i+1]=y[i];
					if(b[x[i+1]][y[i+1]]==0)
					{
						ans++;
						b[x[i+1]][y[i+1]]++;
					}
				}
				else
				{
					d=0;
					x[i+1]=x[i];
					y[i+1]=y[i];
				}
				
			}
		
		}
		
		cout<<ans+1<<endl;
		for(int i=0;i<=k+100;i++)
		{
			b[x[i]][y[i]]=0;
		}
		
		
		
	}
	return 0;
}
