#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N =1e3+5;
const ll INF =1e18;
ll dp[N][N];
int n,m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i =1;i <= n;i++)
	{
		int x;
		cin >> x;
		for(int j =m;j >= 0;j--)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=x)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-x]+1); 
			}
		}
	}
	cout << dp[n][m]-1 << endl;
	return 0;
}
