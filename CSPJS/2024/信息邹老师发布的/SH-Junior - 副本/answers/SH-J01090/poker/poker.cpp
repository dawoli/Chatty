#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 
// 1 <= n <= 52
string a[55];
char buffer[10];

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	scanf("%d", &n);
	// 使用 set 数据结构去重 
	set<string> s1;
	for (int i=1;i<=n;i++) {
		scanf("%s", buffer);
		a[i] = buffer;
		s1.insert(a[i]);
	}
	// 整理卡牌 sort cards
	//	sort(a+1,a+n+1,cmp);
	printf("%d\n", 52-s1.size());
	
	return 0;
} 
