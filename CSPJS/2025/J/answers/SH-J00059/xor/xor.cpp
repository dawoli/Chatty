#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int cnt0=0,cnt1=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i]==1)cnt1++;
		if(a[i]==0)cnt0++;
	}
	if(cnt1+cnt0<n)return 0;
	if(k==1)cout << cnt1;
	if(k==0)
	{
		int ans=0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i]==0)
			{
				ans++;
				continue;
			}
			if(i<n&&a[i]==a[i+1])
			{
				ans++;
				i++;
			}
		}
		cout << ans;
	}
	return 0;
}
