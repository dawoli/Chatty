#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
bool a[4][13];

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	memset(a, false, sizeof(a));
	cin >> n;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		int p;
		if(str[0] == 'D') p = 0;
		if(str[0] == 'C') p = 1;
		if(str[0] == 'H') p = 2;
		if(str[0] == 'S') p = 3;
		if(str[1] > '1' && str[1] <= '9'){
			int b = int(str[1] - '1');
			a[p][b] = true;
		}
		if(str[1] == 'A') a[p][0] = true;
		if(str[1] == 'T') a[p][9] = true;
		if(str[1] == 'J') a[p][10] = true;
		if(str[1] == 'Q') a[p][11] = true;
		if(str[1] == 'K') a[p][12] = true;
	}
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 13; j++){
			if(a[i][j] == false) ans++;
		}
	}
	
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
