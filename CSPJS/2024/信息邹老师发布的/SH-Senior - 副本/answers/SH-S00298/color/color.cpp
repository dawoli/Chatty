#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;

int T,n,a[N],f[N],cnt,ans;

int main()
	{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int I=1;I<=T;I++)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=15)
		{
		ans=0;
			for(int i=0;i<(1<<n);i++)
			{
				cnt=0;
				for(int j=1;j<=n-1;j++)
				{
					int k=j;
					while(k>0)
					{
						if(((i>>(k-1))&1)==((i>>j)&1))
						{
							if(a[j+1]==a[k]) cnt+=a[k];
							break;
						}
						k--;
					}
				}
				ans=max(ans,cnt);
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++) f[i]=0;
		}
	}
	return 0;
	}
