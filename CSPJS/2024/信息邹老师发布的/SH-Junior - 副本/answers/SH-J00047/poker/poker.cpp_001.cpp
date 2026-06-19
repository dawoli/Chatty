#include<bits/stdc++.h>
using namespace std;
int n;
char s[55][55];
char a, b;
int tmp;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	tmp = n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		s[a][b]++;
		if(s[a][b] > 1) tmp--;
	}
	cout << 52 - tmp;
	return 0;
	
}
