//注意此题要解密
//擂台赛，每轮对于每组，给定擂主是0/1，当且仅当擂主的能力大于轮数时胜利，问可能胜利者编号和
//
//部分分:
//n,m<=8:12分
//n,m<=500:32分
//n,m<=5000:40分  同时,T=1
//
//n,m<=8
//此时k<=3，直接暴搜补充人数的a(0<=a<=3) 
//
//n,m<=5000，此时k<=13 (时间有点勉强)
//从第一轮开始枚举，考虑有没有人能锁定结果
//锁定则记录此人编号，否则记录两人变量和(这两个人是命运共同体)
//最终记录第k轮结束后的那个人
//如果暴力，则时间复杂度O(nmk)


#include<bits/stdc++.h>
using namesapce std;
const int maxn=;
int n;
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
	return 0;
}
