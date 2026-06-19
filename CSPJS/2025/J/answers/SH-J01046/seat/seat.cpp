#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int pm = 1,s;
	cin >> s;
	for(int i = 2;i <= n * m;i ++)
	{
		int a;
		cin >> a;
		if(a > s)
		    pm ++;
	}
    int yz = 2 * n;
    if(pm %yz == 0)
    {
    	cout << pm / n;
    	cout <<' ';
    	cout << 1;
    	return 0;
	}
	if(pm %n == 0)
	{
		cout <<pm / n <<' ' << n;
		return 0;
	}
    if(pm % yz > n)
    {
	
		cout << pm / yz *2 +2;
    	cout << ' ';
    	cout << n - pm % n + 1;
	}
	else cout << pm / yz *2+1 << ' ' << pm %n;
	return 0;
}
