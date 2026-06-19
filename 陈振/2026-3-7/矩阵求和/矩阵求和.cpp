// Problem URL:  
// Finish Time: 2026/3/7 17:09:36 AC
// Start Time: 2026/3/7 16:54:32

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,k,s[1001][1001];
int checksum(int x_1,int y_1,int x_2,int y_2)
{
	return s[x_2][y_2]+s[x_1-1][y_1-1]-s[x_1-1][y_2]-s[x_2][y_1-1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>s[i][j];
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	for(int i=1;i<=k;i++)
	{
		int x_1,y_1,x_2,y_2;
		cin>>x_1>>y_1>>x_2>>y_2;
		cout<<checksum(x_1,y_1,x_2,y_2)<<endl;
	}
	return 0;
}