#include <bits/stdc++.h>
using namespace std;

const int N=10e6;
int n,k,ans;
int a[N],b[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i-1] ^ a[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i] && b[i] == k)
		ans++;
		else if (b[i] && b[i+1] == k)
		ans++;
	}
	cout<<ans;
	return 0;
}
