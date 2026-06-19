#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],cnt,ans;
bool b[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) cnt+=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int x=a[i];
			for(int t=i+1;t<=j;t++)
				x=x^a[t];
			bool z=true;	
			for(int t=i;t<=j;t++)
			{
				if(b[t]==true)
				{
					z=false;
					break;
				}
			}
			if(x==k&&z==true)
			{
				ans++;
				for(int t=i;t<=j;t++) b[t]=true; 
		    	break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
