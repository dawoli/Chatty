#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	long long ans = 0;
    for(int i = 1;i <= n;i ++)
    {
    	unsigned long long cnt = a[i];
    	for(int j = i;j <= n;j ++)
    	{
    		if(j != i)
    		   cnt = (cnt ^a[j]);
    		if(cnt == k)
    		{
				ans ++;
				i = j;
    			break;
			}
		}
	}
	cout << ans;
	return 0;
}
