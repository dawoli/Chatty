#include <bits/stdc++.h>
using namespace std;
int ku[2006][1005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,l,a,r,c;
	cin>>t;
	while(t--)
	{
		int n,k,q;
		for(int i=1;i<=n;i++)
		{
			cin>>l;
			for(int j=1;j<=l;j++)
			{
				cin>>ku[i][j];
			}
		}
		while(q--)
		{
			cin>>r>>c;
			if(r==1)
			{
				for(int i=1;i<=n;i++)
	    	    {
	    	    	for(int j=1;j<=l;j++)
		        	{
		    	    	if(ku[i][j]==c)
		    	    	{
		    	    		for(int k=j-n+1;k<=j-2+1;j++)
		    	    		{
		    	    			if(ku[k][j]==1)
		    	    			{
		    	    				cout<<1;
		    	    				break;
								}
							}
						}
		    	    }
		        }
			}
		}
	}
	return 0;
}
