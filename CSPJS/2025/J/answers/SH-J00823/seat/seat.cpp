#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int c, int d){
	return c > d;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int R = a[1], cnt;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(R == a[i]){
			cnt = i;
			break;
		}
	}
	int c = (cnt - 1) / m + 1, r = (cnt - 1) % m + 1;
	cout << c << " ";
	if(c % 2 == 1){
		cout << r;
	}
	else{
		cout << m - r + 1;
	}
	return 0;
}
