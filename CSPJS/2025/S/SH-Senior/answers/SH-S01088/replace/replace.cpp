#include<bits/stdc++.h>
using namespace std;
int n,q,l[1010],sum1,sum2,ll,lef,righ,c[1010],d[1010],e[1010],f[1010],g[1010],x,y,z,v,w;
string s1[1010],s2[1010],l1,l2;
long long ans;
bool flag=1;
bool ee(string xx,string yy,int zz,int ww)
{
	for(int i=0;i<ww;i++)
		if(xx[i]!=yy[zz+i])
			return 0;
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].length();
		if(flag)
		{
			sum1=0;sum2=0;
			for(int j=0;j<l[i];j++)
			{
				if(s1[i][j]=='a')
					continue;
				else if(s1[i][j]=='b')
				{
					if(!sum1)
						sum1=1;
					else
					{
						flag=0;
						break; 
					}
				}
				else
				{
					flag=0;
					break;
				}
				if(s2[i][j]=='a')
					continue;
				else if(s2[i][j]=='b')
				{
					if(!sum2)
						sum2=1;
					else
					{
						flag=0;
						break; 
					}
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
	}
	if(!flag)
	{
		for(int i=1;i<=q;i++)
		{
			ans=0;
			cin>>l1>>l2;
			ll=l1.length();
			for(int j=0;j<ll;j++)
				if(l1[j]!=l2[j])
				{
					lef=j;
					break;
				}
			for(int j=ll-1;j>=0;j--)
				if(l1[j]!=l2[j])
				{
					righ=j;
					break;
				}
			for(int j=1;j<=n;j++)
			{
				if(l[j]<=ll&&l[j]>=righ-lef+1)
				{
					int v=max(ll-l[j],lef);
					for(int k=max(0,righ-l[j]+1);k<=v;k++)
						if(ee(s1[j],l1,k,l[j]))
							if(ee(s2[j],l2,k,l[j]))
								ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<l[i];j++)
				if(s1[i][j]=='b')
				{
					c[i]=j;
					break;
				}
			for(int j=0;j<l[i];j++)
				if(s2[i][j]=='b')
				{
					d[i]=j;
					break;
				}
			e[i]=c[i]-d[i];
			f[i]=l[i]-c[i];
			g[i]=d[i];
		}
		for(int i=1;i<=q;i++)
		{
			ans=0;
			cin>>l1>>l2;
			ll=l1.length();
			for(int j=0;j<ll;j++)
				if(l1[j]=='b')
				{
					x=j;
					break;
				}
			for(int j=0;j<ll;j++)
				if(l2[j]=='b')
				{
					y=j;
					break;
				}
			z=x-y;
			v=ll-x;
			w=y;
			for(int j=1;j<=n;j++)
			{
				if(e[j]==z)
					if(f[j]<=v)
						if(g[j]<=w)
							ans++;
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
