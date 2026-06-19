// 10:47
// 读完题，n <= 5000说明应该是O(n^2) / O(n^2 log n) 
// 长度之和暴力求法求,O(n)
// 最大的话...暂且先算是O(n)
// =>check复杂度为O(n)
//  纯暴力=>复杂度O(n^3)可过前17个点
// 思考：最主要的重复点是check判断了好几次=>优化check
// 所以是蠕动窗口？？？有可能！
// 等等，有问题！方案数不是相邻的！
// 蠕动窗口这样的话就有问题了 
// 所以暴力解法实际上是2^n只能过前6
// 思考：如果知道一数列x符合条件，那么其他比max(x)小的数都可加入，设共y个数，也就是说可以得到2^k满足条件的方案
// 那么该怎么得到呢????
// 将问题转化为：给一堆<=n的数，有多少种方案使总和>n 
//s[i][m] = s[i-1][m] + s[i-1][m-a[i] ]
// 完蛋，肚子疼要炸了
// 机房这空调什么温度啊
// 废了废了，一打字肚子就疼
// 十年OI一场空，肚子一疼见祖宗
// 回头再看第四题，原来我是大伞兵
// 肚子疼的嗷嗷叫，代码空白又爆零 
// 回头再看得分数，贰佰又余个五十 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353; 
const int MAXN = 5010;
int n, a[MAXN], s[MAXN][MAXN], maxa=INT_MAX;


int main(){
//	freopen("polygon.in", "r", stdin);
//	freopen("polygon.out", "w", stdout);
	cin>>n;
	for (int i = 1;i <= n;++i){
		cin>>a[i];
	} 
	for (int i = 1;i<=n;++i){
		maxa = max(maxa, a[i]);
	} 
	s[0][0] = 1;
	for (int i = 1, i <= maxa;++i){
		s[0][maxa] = 0;
	}
	for (int i = 1;i<=n;++i){
		for (int m = 0;m <= maxa;++m){
			int x = m-a[i];
			if (x < 0) x = 0;
			s[i][m] = s[i-1][m] + s[i-1][x];
		}
	}
	return 0;
}
 
