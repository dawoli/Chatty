#include <bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long mymark;
	for(long long i = 1; i <= n * m; i++){
		cin >> a[i];
		if(i == 1){
			mymark = a[i];
		}
	}
	sort(a + 1, a + 1 + n * m, greater<int>());
	for(long long i = 1; i <= n * m; i++){
		if(a[i] == mymark){
			if(((i - 1) / n) % 2 == 0){
				cout << (i - 1) / n + 1 << ' ' << (i - 1) % n + 1; 
			}else{
				cout << (i - 1) / n + 1 << ' ' << (n + 1) - ((i - 1) % n + 1);
			}
			return 0;
		}
	}
	return 0;
} 
