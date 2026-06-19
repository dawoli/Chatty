#include <bits/stdc++.h>
#define C 2147483646
using namespace std;
int all[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int minn = C;
void solve(int n, int num, bool flag)
{
	if(n < 0)
	{
		return;
	}
	if(n == 0 && num < minn)
	{
		minn = num;
		return;
	}
	if(flag != 1)
		solve(n - all[0], num* 10 + 0,0);
	for(int i = 1;i < 10;i ++ )
	{
		solve(n - all[i], num* 10 + i,0);
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n, T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		solve(n, 0, 1);
		if(minn != C)cout<<minn;
		else cout<<-1;
		cout<<endl;
		minn = C;
	}
	return 0;
}
