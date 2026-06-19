#include <bits/stdc++.h>
using namespace std;

int a[110];

bool cmp(int s, int t){
	return s > t;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int t = a[1];
	sort(a+1, a+n*m+1, cmp);
//	for (int i = 1; i <= n*m; i++){
//		cout << a[i] << " ";
//	}
	int h = 1, l = 1;
	for (int i = 1; i <= n*m; i++){
		if (i!=1){
			if (l%2==1){
				if (h!=n) h++;
				else{
					l++;
				}
			} else{
				if (h!=1) h--;
				else{
					l++;
				}
			}
		}
		if (a[i] == t){
			cout << l << " " << h << endl;
		}
	}
	return 0;
}
