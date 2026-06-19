#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
void solve1()
{
    cout << n / 2;
	return;
}
void solve2()
{
	long long sum = 0;
	for (int i = 1;i <= n;i++)
	{
		if (k == 0 && a[i] == 0)
		{
		    sum++;
		}
		else if (a[i] == 1)
		{
			sum++;
		}
	}
	cout << sum;
	return;
}
int main()//异或运算同为0，异为1 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool flag = true,flag2 = true;
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
    	cin >> a[i];
    	if (a[i] != 1)
    	{
    		flag = false;
		}
	}
	if (flag)//满足A 
	{
		solve1();
	}
	else 
	{
        solve2();		
	} 
	return 0;
}
