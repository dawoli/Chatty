#include<bits/stdc++.h>
using namespace std;
int r[100010],n,a[100010]={0};
int main()
{
    cin>>n;
	int s=n,t;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(r[j-1]>r[j])
			{
				t=r[j];
			    r[j]=r[j-1];
			    r[j-1]=t;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[i]!=-1&&a[i]!=1&&a[j]!=-1)
            {
	            if(r[j]<r[i])
	    	    {
				    s=s-1;
                    a[i]=1;
                    a[j]=-1;
			    }
		    }
	    }
	}
	cout<<s<<endl;
	return 0;
}
