#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];
int c[100005];

int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &c[i]);
	}
	_timeb T;
	_ftime(&T);
	srand(T.millitm);
	int idx = rand() % 256 + 1;
	for(int i = 0; i < idx; i++){
		cout << rand() << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
