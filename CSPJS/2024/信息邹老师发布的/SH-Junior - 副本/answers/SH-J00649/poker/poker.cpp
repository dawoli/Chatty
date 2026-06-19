#include<bits/stdc++.h>
using namespace std;
const int maxn = 11;
const int maxm = 55;
int n;
int poker[maxn][maxm];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	memset(poker, 0, sizeof(poker));
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		int color;
		if(s[0] == 'D')	color = 1;
		else if(s[0] == 'C')	color = 2;
		else if(s[0] == 'H')	color = 3;
		else if(s[0] == 'S')	color = 4;
		int val;
		if(s[1] >= '1' && s[1] <= '9')	val = s[1] - '0';
		else if(s[1] == 'A')	val = 1;
		else if(s[1] == 'T')	val = 10;
		else if(s[1] == 'J')	val = 11;
		else if(s[1] == 'Q')	val = 12;
		else if(s[1] == 'K')	val = 13;
		poker[color][val] = 1;
	}
	int cnt = 0;
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 13; j++){
			if(poker[i][j] == 0)	cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
