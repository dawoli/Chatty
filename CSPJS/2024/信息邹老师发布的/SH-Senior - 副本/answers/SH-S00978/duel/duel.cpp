#include<bits/stdc++.h>
using namespace std;

struct duel{
	int level;
	int is_attack;
	int is_out;
};

int main() {
//	freopen("duel.in", "r", stdin);
//	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	duel duels[n];
	for (int i=0; i<n; i++) {
		cin >> duels[i].level;
		duels[i].is_attack = 0;
		duels[i].is_out = 0;
	}
	for (int i=0; i<n; i++) {
		if (duels[i].is_attack == 1) {
			continue;
		}
		for (int j=0; j<n; j++) {
			if (duels[j].is_out==1 || duels[j].is_attack==1) {
				break;
			}
			if (duels[j].level > duels[i].level) {
				duels[j].is_attack = 1;
				duels[i].is_out = 1;
				break;
			}
		}
	}
	int sum = 0;
	for (int i=0; i<n; i++) {
		if (duels[i].is_out != 0) {
			sum++; 
		}
	}
	cout << sum;
	return 0;
}
