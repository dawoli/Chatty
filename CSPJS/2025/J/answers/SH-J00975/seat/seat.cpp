#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 105;
int n, m;
struct node{
	int id;
	int val; 
	int rnk;
};
node a[maxn];
bool cmp1(node x, node y){
	return x.val > y.val;
}
bool cmp2(node x, node y){
	return x.id < y.id;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].val;
		a[i].id = i; 
	}
	
	sort(a + 1, a + n * m + 1, cmp1);
	
	for(int i = 1; i <= n * m; i++){
		a[i].rnk = i;
	}
	
	sort(a + 1, a + n * m + 1, cmp2);
	
	int s = a[1].rnk;
	
	int c, r;
	// c代表小R所在列数，r代表小R所在行数
	if(s % n == 0){
		c = s / n;
		if(c % 2 == 0) r = 1;
		else r = n;
	}else{
		c = s / n + 1;
		if(c % 2 == 1) r = s - (c - 1) * n; 
		else r = m - (s - (c - 1) * n) + 1;
	}
	
	cout << c << ' ' << r << '\n';
	return 0;
}
