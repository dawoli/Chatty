//
/*
数的表示（factorial）
【题目描述】
任何一个数都可以用阶乘的形式来表示：N=a!+b!+….c!，要求 ，并且 尽可
能大。
比如 表示成：6=3! 而不能表示成：6=2！+2！+2！或 6=2！+2！+1！+1！
这样就可以把一个数用阶乘式唯一表示，如：10=3！+2！+2！ 90=5！+4！+3！
程序要求：输入一个数 ，输出 的阶乘式
【输入格式】
一行，为一个整数N
【输出格式】
一行，为所求的式子
【样例 1】
样例输入 #1
10
样例输出 #1
10=3!+2!+2!
【数据范围及提示】

*/

#include <iostream>
using namespace std;
int a[15];
int n;
int res[100010];
int flag = 0;
void dfs(int sum, int now, int no) {
	if (flag == 1) return;
	sum += a[now];
//	cout<<sum<<endl;
	if (sum == n) {
		cout<<n<<"=";
		for(int i=1;i<=no-2;i++) {
			cout<<res[i]<<"!+";
		}
		cout<<res[no-1]<<"!";
		flag = 1;
		return ;
	}
	for(int i=now;i>=1;i--) {
		if (sum + a[i] <= n) {
			res[no] = i;
			dfs(sum, i, no+1);
		}
	}
}
int main(){
	a[1] = 1;
	//预处理阶乘 
	for(int i=2;i<=9;i++) {
		a[i] = a[i-1]*i; 
	}
	cin>>n;
	for(int i=8;i>=1;i--) {
		if (n >= a[i]) {
			res[1] = i;
			dfs(0, i, 2);
			if (flag == 1)return 0;	
		}
	}

	return 0;
}

