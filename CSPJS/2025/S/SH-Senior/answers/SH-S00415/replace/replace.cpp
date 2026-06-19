#include<bits/stdc++.h>
using namespace std;
int l[1001000]={ };
char a1[2020][20020],a2[2020][20020];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
//	nmnm fa[1000100];
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		l[i]=a.size();
		for(int j=0;j<l[i];j++)
		{
			a1[i][j]=a[j];
			a2[i][j]=b[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		string a,b;
		cin>>a>>b;
		string t1,t2;
		int ji=0,jii=0;
		for(int j=0;j<a.size();j++)
		{
			ji=j;
			if(a[ji]!=b[ji])
			{
				while(a[ji]!=b[ji])
				{
					t1[jii]=a[ji];
					t2[jii]=b[ji];
					jii++;
					ji++;
				}
				break;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int f=1;
			if(l[j]==a.size())
			{
				for(int k=0;k<a.size();k++)
				{
					if(a1[j][k]!=a[k])
					{
						f=0;
						break;
					}
				}
				for(int k=0;k<a.size();k++)
				{
					if(a2[j][k]!=b[k])
					{
						f=0;
						break;
					}
				}
				if(f==1)
				{
					ans++;
				}
			}
			else if(jii==l[j])
			{
				for(int k=0;k<l[j];k++)
				{
					if(a1[j][k]!=t1[k])
					{
						f=0;
						break;
					}
				}
				for(int k=0;k<l[j];k++)
				{
					if(a2[j][k]!=t2[k])
					{
						f=0;
						break;
					}
				}
				if(f==1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
