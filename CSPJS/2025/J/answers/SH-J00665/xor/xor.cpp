#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int sum = 0,ans = 0;
	bool f = 0;
	for(int i = 1;i <= n;i++)
	{
		if(!f)
			sum = a[i],f = 1;
		else
			sum ^= a[i];
		if(sum == k)
			ans++,sum = 0,f = 0;
	}
	cout << ans;
	return 0;
} 
