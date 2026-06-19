#include <bits/stdc++.h>
using namespace std;

int n;
bool flag[100];
int h[200];
int ans = 52;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	h['A'] = 1;
	h['2'] = 2;
	h['3'] = 3;
	h['4'] = 4;
	h['5'] = 5;
	h['6'] = 6;
	h['7'] = 7;
	h['8'] = 8;
	h['9'] = 9;
	h['T'] = 10;
	h['J'] = 11;
	h['Q'] = 12;
	h['K'] = 13;
	
	h['C'] = 0;
	h['H'] = 13;
	h['S'] = 26;
	h['D'] = 39;
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		
		int idx = h[s[0]] + h[s[1]];
		if (!flag[idx]){
			flag[idx] = true;
			ans--;
		}
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
