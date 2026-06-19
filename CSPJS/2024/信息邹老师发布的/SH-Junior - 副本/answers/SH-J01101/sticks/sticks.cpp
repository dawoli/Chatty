#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tijgj;
int nbbs[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void solvee(){
	int nbh;
	cin >> nbh;
	int weis = nbh / 7;
	if (nbh % 7 != 0) weis++;
	if (weis == 1){
		if (nbh == 1){
			cout << "-1\n";
			return;
		}
		for (int i = 1; i < 10; i++)
			if (nbbs[i] == nbh){
				cout << i << "\n";
				return;
			}
	}
	else if (nbh % 7 == 0){
		for (int i = 1; i <= weis; i++)
			cout << 8;
		cout << "\n";
		return;
	}
	else if (nbh % 7 == 1){
		cout << 10;
		for (int i = 1; i <= weis - 2; i++)
			cout << 8;
		cout << "\n";
		return;
	}
	else if (nbh % 7 == 2){
		cout << 1;
		for (int i = 1; i <= weis - 1; i++)
			cout << 8;
		cout << "\n";
		return;
	}
	else if (nbh % 7 == 3){
		cout << 200;
		for (int i = 1; i <= weis - 3; i++)
			cout << 8;
		cout << "\n";
		return;
	}
	else if (nbh % 7 == 4){
		cout << 20;
		for (int i = 1; i <= weis - 2; i++)
			cout << 8;
		cout << "\n";
		return;
	}
	else if (nbh % 7 == 5){
		cout << 2;
		for (int i = 1; i <= weis - 1; i++)
			cout << 8;
		cout << "\n";
		return;
	}
	else if (nbh % 7 == 6){
		cout << 68;
		for (int i = 1; i <= weis - 2; i++)
			cout << 8;
		cout << "\n";
		return;
	}
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> tijgj;
	while(tijgj--)solvee();	
	return 0;
} 
