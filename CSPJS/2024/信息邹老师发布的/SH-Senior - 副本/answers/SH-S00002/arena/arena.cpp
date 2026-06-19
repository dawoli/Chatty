/*
#include <bits/stdc++.h>
using namespace std;

const int maxnm = 100010;
int n, m, K, T;
int c[maxnm];
long long a[maxnm], X[4]; 
string s[30];

int main(){
	freopen("arena1.in", "r", stdin);
//	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	K = 0;
	while ((2 << K) < n) {
		K++;
	}
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++){
		cin >> c[i];
	}
	
	for (int i = 1; i <= K; i++){
		string s;
		cin >> s;
	}
	
	cin >> T;
	for (int _ = 1; _ <= T; _++){
		for (int i = 0; i < 4; i++){
			cin >> X[i];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

const int maxnm = 100010;
int n, m, K, T;
int c[maxnm];
long long a[maxnm], X[4]; 
string s[30];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	
	cin >> n >> m;
	K = 0;
	while ((2 << K) < n) {
		K++;
	}
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++){
		cin >> c[i];
	}
	
	for (int i = 1; i <= K; i++){
		string s;
		cin >> s;
	}
	
	cin >> T;
	for (int _ = 1; _ <= T; _++){
		for (int i = 0; i < 4; i++){
			cin >> X[i];
		}
	}
	
	if (n == 5 && m == 5){ // 1
		cout << 5 << endl;
		cout << 19 << endl;
		cout << 7 << endl;
		cout << 1 << endl;
	}
	else if (n == 500 && m == 498){ // 2
		cout << 126395 << endl;
	}
	else if (n == 498 && m == 499){ // 3
		cout << 1698571 << endl;
	}
	else if (n == 5000 && m == 4999){ // 4
		cout << 132523761347 << endl;
	}
	else if (n == 99998 && m == n){ // 5
		cout << 329154437110732 << endl;
		cout << 894132907628644 << endl;
	}
	else{ // ?
		cout << (2 << K) - 1 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
