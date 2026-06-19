#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int a[500001] = {};
	long long num, tgt;
	int score = 0;
	cin >> num >> tgt;
	for(int i = 0; i < num; i++){
		cin >> a[i];
	}
	long long temp = a[0];
	int len = 0;
	for(int i = 0; i < num; i++){
		len++;
		for(int j = len; j >= 0; j--){
			temp = a[i - j];
			for(int k = j; k >= 0; k--){
				temp = (temp ^ a[i - k]);
			}
			if(temp == tgt){
				score++;
				len = 0;
				break;
			}
		}
	}
	cout << score;
	return 0;
} 
