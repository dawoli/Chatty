#include<bits/stdc++.h>
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
int n,q,l,r,ans;
string h[200005][3],x,y;
int main()
{
	fin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		fin>>h[i][1]>>h[i][2];
	}
	while(q--)
	{
		ans=0;
		l=20000000;
		r=0;
		fin>>x>>y;
		for(int i=0;i<x.length();i++)
		{
			if(x[i]!=y[i])
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		string a="",d="";
		for(int i=l;i<=r;i++)
		{
			a+=x[i];
			d+=y[i];
		}
		for(int i=l;i>=0;i--)
		{
			string b="",e="";
			for(int j=i;j<l;j++)
			{
				b+=x[j];
				e+=y[j];
			}
			for(int j=r;j<x.length();j++)
			{
				string c="",f="";
		    	for(int k=j+1;k<=r;k++)
		    	{
		    		c+=x[k];
		    		f+=y[k];
 		    	}
		    	c=b+a+c;
		    	f=e+d+f;
		    	for(int k=1;k<=n;k++)
		    	{
		    		if(h[k][1]==c and h[k][2]==f)
		    		{
		    			ans++;
					}
				}
			}
		}
		fout<<ans<<endl;
	}
} 
