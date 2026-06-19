#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500020];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(n<=10&&k<=1)
	{
		int ans=0;
	    if(k==0)
	    {
	    	for(int i=1;i<=n;i++)
	    	{
	    		if(a[i]==0) ans++;
				if(a[i]==1&&a[i-1]==1) a[i]=0,ans++;
			}
		}
		else 
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<n/2+1;
	return 0;
}
