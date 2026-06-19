#include<bits/stdc++.h>
using namespace std;
int f[12][100010];
int c[10]={6,2,5,5,4,5,6,3,7,6}; 
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,t=10,T;
	cin>>T;
	for(int iii=1;iii<=T;iii++){
	cin>>n;
	t=1;
	for(int j=0;j<=n;j++)
	{
		f[1][j]=1e9;
	}
	f[1][n-6]=0;
	f[1][n-2]=1;
	f[1][n-5]=2;
	f[1][n-4]=4;
	f[1][n-3]=7;
	f[1][n-7]=8;
	for(int x=1;x<=10;x++)
	{
		if(x!=1){
		for(int w=n;w>=0;w--)
		{
			f[x][w]=1e9;
			for(int i=0;i<=9;i++)
			{
				if(w+c[i]>n) continue;
				f[x][w]=min(f[x][w],f[x-1][w+c[i]]+i*t);
			}
		}
	    }
		if(f[x][0]!=1e9)
		{
			
			/*
			for(int i=1;i<=3;i++)
	  	    {
			    for(int j=0;j<=18;j++)
			    {
			    	cout<<f[i][j]<<' ';
			     } 
		    	 cout<<endl;
	    	}
	    	*/
	    	if(f[x][0]/t==0)
	    	{
			    if(x==1)
		      	{
			    	cout<<6<<endl;
			    	break;
		    	}
	    		f[x][0]=1e9;
	    		for(int i=1;i<=9;i++)
		    	{
		    		if(c[i]>n) continue;
			    	f[x][0]=min(f[x][0],f[x-1][0+c[i]]+i*t);
			    }
			}
			cout<<f[x][0]<<endl;
			break;
		}
		t*=10;
		if(x==10) cout<<-1<<endl; 
	}
    }
	return 0;
}
