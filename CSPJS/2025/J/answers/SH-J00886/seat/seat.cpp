#include <bits/stdc++.h>
using namespace std;
struct A{
	int s, id;
}a[105];
bool cmp(A x, A y){
	return x.s > y.s;
} 
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].s;
		a[i].id = i;
 	}
	sort(a+1, a+m*n+1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i].id == 1){
			int c = (i + n - 1) / n;
			cout << c << " ";
			if(c % 2){
				if(i % n == 0){
					cout << n;
				}else{
					cout << i % n;
				}
			}else{
				if(i % n == 0){
					cout << 1;
				}else{
					cout << n - i % n + 1;
				}
			}
			return 0;
		}
	}
}
