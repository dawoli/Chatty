#include <bits/stdc++.h>
using namespace std;
#define ll long long  // 定义long long为ll，简化书写

// 变量说明：
// n：几组分组的长度；m：输入字符串的长度
// cnt：连续出现"abc"子串数量；ans：最终得分（总分）
// x：遍历字符串的指针；a[25]：存储不同abc对应的分数
// dp[40000]：动规数组，dp[j]表示j个"abc"能获得的最大分数
// s：输入的目标字符串
ll n,m,cnt,ans,x,a[25],dp[40000];
string s;

int main()
{
	cin>>n;   // 输入分组数量的长度
	for(int i=1; i<=n; i++) cin>>a[i];   // 输入a[i]：表示选i个"abc"能获得的分数

	cin>>m;   // 输入字符串s的长度
	cin>>s;   // 输入目标字符串

	// 动态规划：初始化背包问题，计算j个"abc"能获得的最大分数
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=m/3+10; j++)
		{
			dp[j]=max(dp[j],dp[j-i]+a[i]);
		}
	}

	s+="  ";   // 给字符串末尾补两个空格，方便遍历到最后时s[x+1]/s[x+2]不会越界
	x=0;   // 初始化遍历字符串的指针
	while(x<m)
	{
		// 检查当前是否是连续的"abc"
		if(s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c')
		{
			cnt++;
			x+=3;    // 指针跳过这3个字符
		}
		else
		{
			// 不是连续abc，累加当前cnt个abc能获得的最大分数
			ans+=dp[cnt];
			cnt=0;   // 重置连续abc计数
			x++;     // 指针后移1位
		}
	}
	// 处理遍历结束后最后一段连续abc（比如字符串最后几位是abc）
	if(cnt!=0) ans+=dp[cnt];

	cout<<ans;   // 输出最终总分
	return 0;
}
