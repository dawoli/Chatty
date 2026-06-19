#include<bits/stdc++.h>
using namespace std;

/*
? 一组数据 ?
看来有规律

最少只能是ceil(n/7)位 

从高到低位, d=1~9 / 0~9:
if ceil((n-s[d])/7) == ceil(n/7)-从高到低第几位:
	就你了 

O(t*(n/7)*9) <= O(50*14286*9) = 6428700 1e6 够用
注：可以明显发现有数学方法，但这个够用 
*/

const int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int t, n; 

int ceildiv(int a, int b) {
	return a/b + ((a%b)!=0);
}

void solve(int x) {
	int l = ceildiv(x, 7), flag = 0;
	for (int i=1; i<=l; i++) {
		for (int d=((i==1)?1:0); d<=9; d++) {
			if (ceildiv(x-s[d], 7) == l-i) {
				cout << d;
				x -= s[d];
				flag = 1;
				break;
			}
		}
	}
	if (!flag) {
		cout << -1;
	}
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		cin >> n;
		solve(n);
		cout << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

