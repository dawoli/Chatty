#include<bits/stdc++.h>
using namespace std;

int n, a, b, cnt;
string s;
bool has[15][5];
int tpof(string s){
	if(s[0] == 'D')
		return 1;
	else if(s[0] == 'C')
		return 2;
	else if(s[0] == 'H')
		return 3;
	else if(s[0] == 'S')
		return 4;
}
int nmof(string s){
	if(s[1] == 'T')
		return 10;
	else if(s[1] == 'J')
		return 11;
	else if(s[1] == 'Q')
		return 12;
	else if(s[1] == 'K')
		return 13;
	else
		return s[1] - '0';
}
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> s;
		a = nmof(s), b = tpof(s);
		if(has[a][b] == false){
			++cnt;
			has[a][b] = true;
		}
	}
	cout << 52 - cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

