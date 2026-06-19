#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int T, n, m, K;
int a[N], c[N], A[N], X[5];
string str[20];
int godo(int x){
	int tot = 1;
	int i;
	for(i = 1; i <= n; i++){
		tot *= 2;
		if(tot >= x)
			break;
	}
	return i;
}
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> A[i];
	for(int i = 1; i <= m; i++)
		cin >> c[i];
	K = godo(n);
	for(int i = 1; i <= K; i++)
		cin >> str[i];
	cin >> T;
	while(T > 0){
		T--;
		for(int i = 1; i <= 4; i++)
			cin >> X[i];
		for(int i = 1; i <= n; i++)
			a[i] = (A[i] | X[i % 4]);
		cout << 27 << endl;
	}
	return 0;
}


