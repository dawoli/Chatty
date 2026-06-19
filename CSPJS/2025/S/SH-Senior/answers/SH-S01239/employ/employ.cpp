#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
char c[505];
int lim[505];
int p[505];
int n, m;
int neverpass[505];
void solve1(){
	for (int i = 1; i <= n; i++){
		p[i] = i;
	}
	int cnt = 0;
	bool flag = true;
	do{
		int abandon = 0;
		int pass = 0;
		for (int i = 1; i <= n; i++){
			if (abandon >= lim[p[i]] || c[i] == '0'){
				abandon++;
			} else {
				pass++;
			}
		}
		if (pass >= m) cnt++;
		cnt %= mod;
		if (flag){
//			cout << pass << " " << abandon << endl;
			flag=0;
		}
		
	}while(next_permutation(p + 1, p + n + 1));
	cout << cnt << endl;
}
void solve2(){
	//此时全部录用，题目必须全部是1，所以乱排就可以了,不然就是0 
	bool flag = 1;
	for (int i = 1; i <= n; i++){
		if (c[i] == '0'){
			flag = 0;
			break;
		}
	}
	for (int i = 1; i <= n; i++){
		if (lim[i] == 0){
			flag = 0;
			break;
		}
	}
	if (flag){
		int mul = 1;
		for (int i = 1; i <= n; i++){
			mul *= i;
			mul %= mod;
		}
		cout << mul;
	}else{
		cout << 0;
	}
}
void solve3(){
	//此时只录用一个 
	//只需统计一个都不录用的情况
	//每一个'1'都必须选择会放弃的
	//将lim排序，处理出每一个'1'的选择范围，'0'随便乱选，然后乘法原理
	int mul = 1;
	for (int i = 1; i <= n; i++){
		mul *= i;
		mul %= mod;
	}
	sort(lim + 1, lim + n + 1);
	int mul2 = 1, cnt0 = 0, cnt1 = 0;
	for (int i = 1; i <= n; i++){
		if (c[i] == '0'){
			cnt0++;
		} else {
			cnt1++;
			neverpass[cnt1] = n;
			for (int j = 1; j <= n; j++){
				if (lim[j] > i - 1){
					neverpass[cnt1] = j - 1;
					break;
				}
			}
		}
	}
//	cout << neverpass[1] << neverpass[2];
	for (int i = 1; i <= cnt1; i++){
		mul2 *= (neverpass[i] - i + 1);
		mul2 %= mod;
//		cout << mul2 << " ";
	}
	
	for (int i = 1; i <= cnt0; i++){
		mul2 *= (n - cnt1 - i + 1);
		mul2 %= mod;
	}
	cout << (mul - mul2) % mod;
}


signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> lim[i];
	}
	if (n <= 10){
		solve1();
	}
	else if (n == m){
		solve2();
	}
	else if (m == 1){
		solve3();
	} else {
		
		cout << 0;
	}
} 

