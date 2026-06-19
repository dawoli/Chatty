#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,i,j,k,b=0;
	cin>>n>>k;
	int a[n+10],al=0,all=0;
	vector<int> c,d,e,f;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	    if(a[i]!=0&&a[i]!=1)al=1;
	    if(a[i]!=1)all=1;
	}
	if(al==1)
	{
		for(i=1;i<=n;i++)
	    {
	        int num=a[i];
	        for(j=i+1;j<=n;j++)
	        {
	         	num^=a[j];
	        	if(num==k)
		     	{
			    	c.push_back(a[i]);
			    	d.push_back(a[j]);
			    } 
	    	}
     	}
    	int ans=c.size();
    	for(i=0;i<c.size()-1;i++)
    	{
	    	for(j=i+1;j<d.size();j++)
	    	{
		    	if(c[i]>=d[j])
		    	{
		        	e.push_back(c[i]);
		        	f.push_back(d[j]);
		    		ans--;
		    	}
	    	}
	     }
     	for(i=0;i<e.size()-1;i++)
	    {
		    for(j=i+1;j<f.size();j++) 
	    	{
		    	if(e[i]<f[j])ans++;
	    	}
	    }
	    cout<<ans;
	}
    else
	{
	    if(all!=1)cout<<n/2;
	    else 
	    {
	    	int ans=0;
	        int q=0;
	    	for(i=1;i<=n;i++)
	    	{
	    		if(q^a[i]==k)
	    		{
	    			ans++;
	    			q=0;
				}
			}
			cout<<ans;
		}
	}     
	return 0;
}
