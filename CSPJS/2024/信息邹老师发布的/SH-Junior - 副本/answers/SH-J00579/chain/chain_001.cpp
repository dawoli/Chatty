#include<bits/stdc++.h>
using namespace std;
long long s[1005][2005],l[100005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++) cin>>s[i][j];
		}
		for(int i=1;i<=q;i++)
		{
			long long r,c;
			cin>>r>>c;
			bool flag=false;
			if(r==1&&c<=k)
			{
				for(int j=1;j<=n;j++)
				{
					for(int h=1;h<=l[j];h++)
					{
						if(s[j][h]==1 && l[j]-h>=1)
						{
							flag=true;
							break;
						}
					}
				}
			}
			cout<<flag<<endl;
		}
	}
	return 0;
}
