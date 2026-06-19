#include<bits/stdc++.h>
using namespace std;
const int bt[22] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 40, 48, 58, 80, 88, 108, 188, 228, 208, 288, 688};
int T, n, minn = 2e9;
string minp, p;
void dfs(int x, int sum, int st) // x 位数  sum 目前的和  
{
	if(sum > n) return;
	if(x > minn) return;
	if(sum == n) if(x < minn || p < minp) minp = p, minn = x;
	for(int i = st; i <= 7; i++) p[x] = '0' + i, dfs(x + 1, sum + i, i);
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n % 7 == 0) // A
		{
			for(int i = 1; i <= n / 7; i++) cout<<8;
			cout<<endl;
		}
		else if(n % 7 == 1) // B (to be proved)
		{
			int k = (n - 1) / 7;
			cout<<10;
			for(int i = 1; i <= k - 1; i++) cout<<8;
			cout<<endl;
		}
		else if(n <= 20) cout<<bt[n]<<endl;
		else
		{
			dfs(0, 0, 2);
			if(minn != 2e9) for(int i = 0; i < minn; i++) cout<<bt[minp[i]];
			else cout<<-1;
			cout<<endl;
		}
	}
	return 0;
}
