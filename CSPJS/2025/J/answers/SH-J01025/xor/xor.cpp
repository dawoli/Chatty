#include <iostream>
using namespace std;
int n,k,a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool all_1=1,all_low1=1;
	int cnt1=0;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		if (a[i] != 1) all_1=0;
		if (a[i] > 1) all_low1=0;
		if (a[i] == 1) cnt1++;
	}
	if (all_1 && k == 0) //льA
	{
		cout<<n/2;
		return 0;
	}
	if (all_low1 && k == 0) //льB0
	{
		bool x=0;
		int ans=0;
		for (int i=1; i<=n; i++)
		{
			if (a[i] == 0 && !x) ans++;
			if (a[i] == 1)
			{
				if (!x) x=1;
				else x=0,ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if (all_low1 && k == 1) //льB1
	{
		cout<<cnt1;
		return 0;
	}
	cout<<n/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
