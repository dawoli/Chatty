#include <bits/stdc++.h>

using namespace std;

int n, m;
int pat[505];
char a[505];

int main(){
	freopen("employ.in", "w", stdin);
	freopen("employ.out", "r", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> pat[i];
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
