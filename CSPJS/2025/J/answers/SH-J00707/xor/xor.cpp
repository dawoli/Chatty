#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int cnt=0;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(a[i-1]==1)
				{
					ans+=cnt/2;
				}
				ans++;
			    cnt=0;
			}
			else
		    {
		    	cnt++;
			}
		}
		ans+=cnt/2;
		cout << ans;
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)cnt++;
		}
		cout << cnt;
	}
	return 0;
}
