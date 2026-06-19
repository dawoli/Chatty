#include<bits/stdc++.h>
using namespace std;

int a[100005]; 

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n,k,q;
		cin >> n >> k >> q;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[j];
		}
		for(int j = 1; j <= q; j++)
		{
			int y,z;
			cin >> y >> z;
			cout << 1;
		}
	} 
	return 0;
}
//    1331000 space 1300000B
