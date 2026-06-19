// 14:30
// 崩溃了，第一题难度就这么大，DP？贪心？
// 14：:50
// T2看了，根本不会，最小生成树Prim早忘了
// 15:10
// T3看了，还是不会，什么东西啊？ 
// 15:12
// T4看了，一脸懵逼，早知道不来考S组复赛了，回去还要挨骂.....
// 15:15
// 完蛋，直接开始暴搜吧 
// 15:36
// 暴搜写完了，写大样例了 
// 15:45
// 特殊性质A写完了 
// 15:51
// 思考：假设初始的时候所有人都安排在1号团
// => 将ai1都变成0，那么ai2和ai3都是+和-
// => 将至少n/2个人安排进2/3，那么ans = (sum a1） + ai2、ai3最大 
// 17:39 
// 这次考试绝对考砸了，T1只写了暴力骗分，T2暴力写不出来,T3倒在判断string长度上了，T4太复杂了完全不会 
// 怎么办？只能躺平了，预估40pts
// 哎，早知道不来考s组的，一堆东西学了又忘，dp往深一点就不会了，最小生成树学了但仅限模版，二分答案现在还弄不懂，dijiesitela跟拖大便一样，完全不会
// 我为什么要来学OI??? 
#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 100010;
int t, n, a[MAXN][3], d[MAXN], ans,flag=true, a1[MAXN];


void calc(){
	int num=0, check[3]={0};
	for (int i = 1; i <= n;++i){
		num+=a[i][d[i]];
		check[d[i]]++;
	}
	for (int i = 0;i < 3;++i){
		if (check[i]>(n/2)) return;
	}
	ans = max(ans, num);
	return;
}


void dfs(int k){
	if (k == (n + 1)){
		 calc();
		 return;
	}
	for (int i =0;i < 3;++i){
		d[k] = i;
		dfs(k+1);
	}
	return;
} 


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	for (int i = 0;i < t;++i){
		ans = INT_MIN;
		cin>>n;
		for (int x = 1;x <= n;++x){
			cin>>a[x][0]>>a[x][1]>>a[x][2];
			if (a[x][1]!=0||a[x][2]!=0){
				flag = false;
			}
			a1[x] = a[x][0];
		}
		if(flag){
			sort(a1, a1+n);
			ans = 0;
			for (int i = 1;i<=(n/2);++i){
				ans += a1[n-i+1];
			}
			cout<<ans;
			return 0;
		} 
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
 
