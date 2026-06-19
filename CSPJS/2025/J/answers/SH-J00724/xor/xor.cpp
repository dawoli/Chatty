#include <bits/stdc++.h>
#define lol long long 
using namespace std;

int a[500005];
int n,k;

bool f1 = 1;

bool f2 = 1;

lol cnt[5];

lol ams;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin>>n>>k;
	for(int i = 1;i <= n;i ++)
	{
		cin>>a[i];
		if(a[i] != 1) f1 = 0;
		if(a[i] > 1) f2 = 0;
		
		if(a[i] == 1 || a[i] == 0)
		{
			cnt[a[i]] ++;
		}
		if(a[i] == k) ams ++;
	} 
	
	if(f1)
	{
		cout<<n / 2<<'\n';
		return 0;
	}
	
	int ff = 0;
	
	if(f2)
	{
		if(k == 1)
		{
			cout<<cnt[1]<<'\n';
			return 0;
		}
		else if(!k)
		{
			for(int i = 1;i <= n;i ++)
			{
				if(a[i] == a[i + 1])
				{
					ff++;
					i += 2;
				}
			}
			cout<<cnt[0] + ff<<'\n';
			return 0;
		}
	}
	
	cout<<ams<<'\n';
	
	return 0;
}
