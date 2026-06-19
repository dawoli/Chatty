#include<bits/stdc++.h>
using namespace std;
long long n,k,ans = 0;
long long a[500005];
bool flaga = true;
bool flagb = true;
long long f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != 1) flaga = false;
		else if(a[i] != 1 && a[i] != 0) flagb = false;
		else flaga = flaga;
	}
	if(flaga) ans = k / 2;
	else if(flagb)
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == k)
			{
				f[i] = 1;
				ans++;
			}
			else
			{
				if(a[i - 1] != k && f[i - 1] == 0) 
				{
					f[i] = 1;
					ans++;
				}
			}
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			long long now = a[i];
			if(now == k) 
			{
				ans++;
				//cout<<i<<" "<<i<<endl;
			}
			else
			{
				for(int j = i + 1;j <= n;j++)
				{
					now ^= a[j];
					if(now == k)
					{
						ans++;
						//cout<<i<<" "<<j<<endl; 
						i = j;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
