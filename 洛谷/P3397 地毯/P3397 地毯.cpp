// Problem URL: https://www.luogu.com.cn/problem/P3397
// Finish Time: 2026/3/7 18:02:32 AC
// Start Time: 2026/3/7 17:52:22

#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;
typedef long long int ll;
int n,m,s[MAXN][MAXN],x_1,y_1,x_2,y_2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x_1>>y_1>>x_2>>y_2;
		s[x_1][y_1]++;
		s[x_1][y_2+1]--;
		s[x_2+1][y_1]--;
		s[x_2+1][y_2+1]++;
	}
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=n;j++)
		{
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			cout<<s[i][j]<<' ';
		}
	return 0;
}