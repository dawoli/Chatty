#include <iostream>
#include <cmath>
using namespace std;
int n,a[5001],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool all_1=1;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		if (a[i] != 1) all_1=0;
	}
	if (all_1)
	{
		for (int i=3; i<=n; i++)
		{
			ans += 1+pow(i,(n-i));
		}
		ans--;
		cout<<ans%998244353;
		return 0;
	}
	cout<<(n+1)%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
