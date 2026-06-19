#include<bits/stdc++.h>
using namespace std;
int a,b[100000],c[100000],f[100000],e,q,l;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a-1;i++) 
	{
	cin>>b[i];
    }  
    int d;
    d=0;
    c[0]=b[0];
    f[0]=1;
    for(int k=1;k<=a-1;k++)
    for(int j=0;j<=a-1;j++)
    {
    	if(c[j]==b[k]) 
    	{
    		f[j]+=1;
    		break;
		}
        else if(j>d)
        {
        	d+=1;
        	c[j]=b[k];
        	f[j]=1;
        	break;
		}
	}
	for(int m=0;m<=d;m++)
	{
		if(c[m]>c[m+1]) 
		{
			e=c[m];
			q=f[m];
			c[m]=c[m+1];
			f[m]=f[m+1];
			c[m+1]=e;
			f[m+1]=q;
		}
	}
	l=0;
	cout<<d;
	return 0;
} 
