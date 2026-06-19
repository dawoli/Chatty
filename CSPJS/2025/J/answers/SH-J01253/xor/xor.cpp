#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin >> n >> k;
	long long a[n],b[n]={0};
	for(long long i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(long long i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			ans++;
			b[i]=1;
		}
	}
	for(long long i=2;i<=n;i++)
	{
		for(long long j=0;j<=n-i;j++)
		{
			bool h=1;
			for(long long p=j;p<i+j;p++)
			{
				if(b[p]==1)
				{
					h=0;
				}
			}
			if(h)
			{
				long long s=a[j];
				for(long long p=j+1;p<j+i;p++)
				{
					s=s xor a[p];
				}
				if(s==k)
				{
					ans++;
					for(long long p=j;p<j+i;p++)
					{
						b[p]=1;
					}
				}	
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
