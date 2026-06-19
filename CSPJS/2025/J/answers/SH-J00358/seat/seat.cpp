/*
2 2
98 99 100 97
	
3 3
94 95 96 97 98 99 100 93 92

*/
#include<bits/stdc++.h>
using namespace std;

int a[101];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int xr = a[1];
	//paixu
	for (int i = 1; i <= n * m; i++){
		for (int j = i + 1; j <= n * m; j++){
			if (a[j] > a[i]){
				swap(a[i], a[j]);
			}	
		}
	}
//	for (int i = 1; i <= m * n; i++){
//		cout << a[i] << " ";
//	}
	
	if (n <= 1){
		for (int i = 1; i <= n * m; i++){
			if (a[i] == xr){
				cout << i << " " << n << endl;
				return 0;
			}
		}
		return 0;
	}
	
	if (m <= 1){
		for (int i = 1; i <= n * m; i++){
			if (a[i] == xr){
				cout << m << " " << i << endl;
				return 0;
			}
		}
	}
	
	int mi = 1, ni = 1;
	if (n <= 2){
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= m; j++){
				if (a[i * j] == xr){
					cout << mi << " " << ni << endl;
					return 0;
				}
				if (mi % 2 == 1 && ni == 1){
					ni++;
				}
				else if (mi % 2 == 1 && ni == 2){
					continue;
				}
				else if (mi % 2 == 0 && ni == 2){
					ni--;
				}
				else if (mi % 2 == 0 && ni == 1){
					continue;
				}
			}
			mi++;
		}	
	}
	else{
		
	}
	
	return 0;
}
