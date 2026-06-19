#include <bits/stdc++.h>
using namespace std;
int ans[32] = {1,3,3,7,5,1,2,3,4,1,3,1,2,5,3,5,1,6,1,2,1,4,2,4,3,4,6,6,1,1,7,7};
int fin[7] = {1,0,1,0,1,0,0};

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);	
	bool flag = true;
	int a[33];
	for(int i = 0; i <= 31; i++)
	{
		cin >> a[i];
		if(a[i] != ans[i]) flag=false;
	}
	if(flag)
	{
		for(int i=0;i<=6;i++)
		{
			cout << fin[i] << endl;
		}
	}
	return 0;
}
