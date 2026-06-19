#include<bits/stdc++.h>

using namespace std;
const int N = 200;
int n, m, q;
int a[N];
//struct xxx{
//	int fen, ren;
//}aaa[N];
//
//bool comp(xxx qq, xxx pp){
//	return qq.fen < pp.fen;
//}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1]; q = a[1];
	for(int i = 2; i <= n*m; i++){
		cin >> a[i];
	}
	sort(a+1, a+n*m+1);
//	for(int i = 1; i <= n*m; i++){
//		cout << a[i] << " " << q << endl;
//	}
	for(int i = 0; i < n*m; i++){
//		cout << n*m-i << endl;
		if(a[n*m-i] == q){
			int qq = (i+1)/(2*n), pp = (i+1)%(2*n);
			if(pp == 0){
				cout << qq*2 << " " << n;
			}else if(pp <= n){
				cout << qq*2+1 << " " << pp;
			}else{
				cout << qq*2+2 << " " << 2*n-pp+1;
			}
			break;
		}
	}
	return 0;
}
