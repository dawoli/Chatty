// CSP-S 打满暴力就是一等奖
/* 做法
 * 1 1 2 2 3
 * 2 2 3
 * 2 3
 * 
 * 桶数组计数 X
 * 如 #1 = {0, 2, 2, 1}
 * 2 -> 1, 3 -> 2
 * 显然可以更改 a_{i - 1} = a{i - 1} - a{i}
 * hack: 1 1 2 3 3 3
 * 
 * 存变量 + queue
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

const int N = 1e5 + 5;
const int R = 1e5 + 5;
map <int, int> buk;
queue <int> sv;

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	//ios::syn _with_stdio(0); cin.tie(0);
	//cout.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0, x; i < n; i ++){
		cin >> x;
		buk[x] ++; 
	}
	
	for (auto it : buk) sv.push(it.second);
	if (sv.size() == 1){
		cout << n;
		return 0;
	}
	
	int a = sv.front(); sv.pop();
	while (sv.size()){
		int b = sv.front(); sv.pop();
		a = max(0, a - b);
		a += b;
	}
	
	cout << a;
	return 0;
}
