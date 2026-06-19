#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tijgj;
int nb, mb, kb;
int xh, yu, dff;
char charr[1010][1010];
int shibs[1010][1010];
int fangf[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool checkk(int xd, int yt){
	if (xd < 1 || xd > nb || yt < 1 || yt > mb) return 0;
	if (charr[xd][yt] == 'x') return 0;
	return 1;
} 
void solvee(){
	cin >> nb >> mb >> kb >> xh >> yu >> dff;
	for (int i = 1; i <= nb; i++){
		for (int j = 1; j <= mb; j++){
			cin >> charr[i][j];
			shibs[i][j] = 0;
		}
	}
	shibs[xh][yu] = 1;
	int xxx = xh, yyy = yu, ddd = dff;
	for (int i = 1; i <= kb; i++){
		int xcc = xxx + fangf[ddd][0];
		int ycc = yyy + fangf[ddd][1];
		if (checkk(xcc, ycc) == 1){
			xxx = xcc;
			yyy = ycc;
		}
		else{
			ddd = (ddd + 1) % 4;
		}
		shibs[xxx][yyy] = 1;
	}
	int ttxo = 0;
	for (int i = 1; i <= nb; i++){
		for (int j = 1; j <= mb; j++){
			if (shibs[i][j] == 1)
				ttxo++;
		}
	}
	cout << ttxo << '\n';
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> tijgj;
	while(tijgj--)solvee();
	return 0;
} 
