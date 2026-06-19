#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() 
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int n;
		cin>>n;
		int a[2010]={};
		int b[2010]={};
		int p[2010]={};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			
			if(p[a[i]]==0)
			{
				for(int j=i;j<=n;j++)
				{
					if(a[i]==a[j])
					p[a[i]]++;
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]!=0)
			{
				ans+=(p[i]-1)*i;
			}
		
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
