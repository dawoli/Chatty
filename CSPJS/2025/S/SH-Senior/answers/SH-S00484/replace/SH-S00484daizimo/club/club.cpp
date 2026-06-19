#include<bits/stdc++.h>
using namespace std;

int t; // t组数据，记得memset 
int n; // n个人
const int N = 1e5 + 5;
int arr[N][5] = {0};
int dp[N][5] = {0};
int have[N][5] = {0}; // 这个部门有多少人 

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++) cin>>arr[i][j];
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				if(have[i - 1][j] + 1 >= n / 2)
				{
					have[i][j] = have[i - 1][j];
					dp[i][j] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3]));
				}
				else
				{
					have[i][j] = have[i - 1][j] + 1;
					dp[i][j] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3])) + arr[i][j];
				}
//				cout<<dp[i][j]<<" ";
//				cout<<have[i][j]<<" ";
			}
//			cout<<"\n";
		}
		cout<<max(max(dp[n][1], dp[n][2]), dp[n][3])<<endl;
//		cout<<have[n][1]<<" "<<have[n][2]<<" "<<have[n][3]<<endl;
		memset(dp, 0, sizeof(dp));
		memset(have, 0, sizeof(have)); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
