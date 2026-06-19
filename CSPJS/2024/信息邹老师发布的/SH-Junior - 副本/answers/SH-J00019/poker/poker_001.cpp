#include<bits/stdc++.h>
using namespace std;

int n;
bool used[1009][1009];

int main(){	
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		char x, y;
		cin >> x >> y;
		if(used[x][y] == false){
			used[x][y] = true;
		}
	}
	
	int sum = 0;
	for(int i = 1; i <= 109; i ++){
		for(int j = 1; j <= 109; j ++){
			if(used[i][j] == true) sum ++;
		}
	}
	int ans = 52 - sum;
	cout << ans;
	
	return 0;
}
