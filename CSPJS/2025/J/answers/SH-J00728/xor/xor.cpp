#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[500005];

bool check(int mid)
{
	int count = 0;
	long long num = 0;
	for(int i = 1;i<=n;i++)
	{
		if(num^a[i]==k)
		{
			count++;
			num=0;
			if(count>mid)
			{
				return 0;
			}
		}
		else
		{
			num^=a[i];
		}
	}
	if(count!=mid)
	{
		return 0;
	}
	return 1;
}


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	cout << check(2)<<endl;
	long long l = 1,r=n;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout << l <<endl;
	return 0;
}
