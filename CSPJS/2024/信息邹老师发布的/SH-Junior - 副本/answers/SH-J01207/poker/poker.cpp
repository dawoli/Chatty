#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, cnt, encode[131];
bool man[5][15];
char card[11];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%lld", &n);
	encode['D'] = 1;
	encode['C'] = 2;
	encode['H'] = 3;
	encode['S'] = 4;
	for (ll i = 2;i <= 9;i++){
		encode[i + '0'] = i;
	}
	encode['A'] = 1;
	encode['T'] = 10;
	encode['J'] = 11;
	encode['Q'] = 12;
	encode['K'] = 13;
	for (ll i = 1;i <= n;i++){
		cin >> card;
		man[encode[card[0]]][encode[card[1]]] = 1;
	}
	for (ll i = 1;i <= 4;i++){
		for (ll j = 1;j <= 13;j++){
			if (man[i][j]){
				cnt++;
			}
		}
	}
	cnt = 52 - cnt;
	printf("%lld", cnt);
	return 0;
}
