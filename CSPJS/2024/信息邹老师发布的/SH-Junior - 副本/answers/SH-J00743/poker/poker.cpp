#include <bits/stdc++.h>
using namespace std;

int poker[300][300];
string iIn = "DCHS";
string jIn = "A23456789TJQK";
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	char col, num;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> col >> num;
		poker[col][num] = 1;
	}
	int cont = 0;
	for (char i: iIn){
		for (char j: jIn){
			if (!poker[i][j]){
				++cont;
			}
		}
	}
	cout << cont;
	return 0;
}
