// Categories: 动态规划
#include <bits/stdc++.h>
// Finish Time: 2026/2/24 08:48:56 AC
using namespace std;
int dp[110][110]; // dp[i][j] 表示区间[i,j]最少添加字符数
int main()
{
	string s;
	cin>>s;
	int l=s.size();
	// 初始化
	for(int i=0; i<l; i++) // 长度为1需要填1个字符
		dp[i][i]=1;
	for(int i=0; i<l-1; i++)
	{ // 长度为2
// if((s[i]=='('&&s[i+1]==')' || s[i]=='['&&s[i+1]==']')){
//     dp[i][i+1] = 0;
// }
		if(!(s[i]=='('&&s[i+1]==')'||s[i]=='['&&s[i+1]==']'))
		{
			dp[i][i+1]=2; // 其它长度2的最优解为2
		}
	}
	for(int len=3; len<=l; len++)
	{ // 枚举长度
		for(int i=0; i+len-1<l; i++)
		{ // 枚举起点
			int j=i+len-1; // 计算终点
			// 转移方式1：两端匹配
			if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']')
				dp[i][j]=dp[i+1][j-1];
			else
				dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);
			// 转移方式2：小区间合并大区间
			for(int k=i; k<j; k++)
			{ // 枚举分割点
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout<<dp[0][l-1]; // 输出结果
	return 0;
}