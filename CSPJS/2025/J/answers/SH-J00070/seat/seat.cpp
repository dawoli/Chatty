#include <bits/stdc++.h>
using namespace std;

const int maxn(105);
int a[maxn];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int r = a[1];
	int cnt(0);//–°RŒª÷√ 
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == r){
			cnt = i;
		}
	}
//	int n = 4;
//	int m = 5;
//	int cnt = 3;
	int m_ =  (cnt - 1) / n + 1;
	int n_;
	if(m_ % 2 == 0){
		n_ = n - ((cnt - 1) % n + 1) + 1;
	}else{
		n_ = ((cnt - 1) % n + 1);
	}
//	for(int i = 1; i <= n * m; i++){
//		cout << a[i] << ' ';
//	}
//	cout << endl;
	cout << m_ << ' ' << n_;
	return 0;
}
