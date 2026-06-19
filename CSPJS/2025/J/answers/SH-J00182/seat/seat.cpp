#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N][N] , b[N * N];
bool cmp(int a , int b){
	return a > b;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> b[i];
	}
	int r = b[1];
	sort(b + 1 , b + n * m + 1 , cmp);
	int x = 1;
	for(int j = 1; j <= m; j++){
		if(j % 2){
			for(int i = 1; i <= n; i++){
				a[i][j] = b[x];
				x++;
			}
		}else{
			for(int i = n; i >= 1; i--){
				a[i][j] = b[x];
				x++;
			}
		}
	}
	int ansi , ansj;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == r){
				ansi = i;
				ansj = j;
			}
		}
	}
	cout << ansj << ' ' << ansi;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
