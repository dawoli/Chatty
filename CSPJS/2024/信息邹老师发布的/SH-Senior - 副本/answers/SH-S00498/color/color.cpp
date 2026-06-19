#include<bits/stdc++.h>
using namespace std;
int T,n,a[25],colour[25],ans;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    for(int i=1;i<=n;i++)
	        cin>>a[i];
	    if(n>20)
	    {
	    	cout<<0<<"\n";
	    	continue;
		}
		ans=0;
		for(int i=0;i<(1<<n);i++) //1101
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			    colour[j]=(i>>(j-1))%2;
			for(int j=1;j<=n;j++)
			{
				for(int k=j-1;k>=1;k--)
				{
					if(colour[j]==colour[k]&&a[j]==a[k])
					{
						cnt+=a[j];
						break;
					}
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}


