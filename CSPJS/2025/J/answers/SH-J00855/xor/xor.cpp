// 9:20  
// n = 5 * 10 ^ 5 => O(n) / o(n log n) DP？？？ 二分答案？？？ 
// 0 <= ai, k <= 2^20 开int128??? 还是其它做法 
// 异或可以用前缀和吗？？？ 
// s[a] = 1 s[b] = 0 => s[a, b] = 1 
// s[a] = 0 s[b] = 0 => s[a, b] = 0
// s[a] = 1 s[b] = 1 => s[a, b] = 0
// s[a] = 0 s[b] = 1 => s[a, b] = 1
// s[a, b] = s[a] 异或 s[b] 
// 也就是说check(a, b)可以通过预处理实现O(1) DP???
// 假设f(i) = [1, i] 最多数量 
//                       i
// 也就是说f(i) =  max((max f(i - r) + 1 | check(i-r, i) == 1) ， f(i-1)) 
//                      r=1
// 等等，这不是复杂度O(n^2)了吗？？？ 
// 9:48，感觉要完蛋,不管了，先写DP再说 
// 等等，异或是啥字母？？？ 
// ^&*%!~?/+-|=: 
// 完蛋啦，自己写一个吧 
// 10:14
// 我是扇贝！！！就是^!!!浪费了30min.... 
//10:33
// 代码敲完了，前3个样例过了，倒在第5个了... 
// 10:41
// 调完了，复杂度听天由命吧.... 等等！差点忘了该死的2^20 
// 十年OI一场空，不开longlong见祖宗
// 10:44 弄完了还有1h20min加油干下一道 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
#define lll __int128 
int n, k, F[MAXN];
lll a[MAXN], t[MAXN];

bool check(lll a, lll b){
	a--;
	lll result = t[a] ^ t[b];
	if (result == k){
		return true;
	}
	else{
		return false;
	}
}



int main(){
	 freopen("xor.in", "r", stdin);
	 freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for (int i = 1; i<= n;++i){
		cin>>a[i];
	}
	t[1] = a[1];
	for (int i =2;i<=n;++i){
		t[i] = t[i-1] ^ a[i];
	}
	F[0] = 0;
	for (int i = 1;i<=n;++i){
		F[i] = INT_MIN;
		for (int r = 0;r<=n;++r){
			if (check(i - r, i)){
				F[i] = max(F[i], F[i - r - 1] + 1);
//				cout<<i<<" "<<r<<" "<<F[i]<<endl;
			}
		}
		F[i] = max(F[i], F[i-1]);
	}
//	for (int i = 1;i<=n;++i) cout<<F[i]<<" ";
	cout<<F[n];
	return 0;
}
 
