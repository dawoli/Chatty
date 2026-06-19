#include <bits/stdc++.h>
using namespace std;

int n;
int mark;
string pok;
int D[14];
int C[14];
int H[14];
int S[14];
int ans = 52;

int main( ){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	for (int i = 0; i < n; i++){
		cin>>pok;
		if (pok[1] == 'A'){
			mark = 1;
		}
		if (pok[1] == 'T'){
			mark = 10;
		}
		if (pok[1] == 'J'){
			mark = 11;
		}
		if (pok[1] == 'Q'){
			mark = 12;
		}
		if (pok[1] == 'K'){
			mark = 13;
		}
		if (pok[1] <= '9' and pok[1] >= '2'){
			mark = pok[1] - 48;
		}
		if (pok[0] == 'D'){
			if (D[mark] == 1){
				continue;
			}
			D[mark] = 1;
			ans--;
		}
		if (pok[0] == 'C'){
			if (C[mark] == 1){
				continue;
			}
			C[mark] = 1;
			ans--;
		}
		if (pok[0] == 'H'){
			if (H[mark] == 1){
				continue;
			}
			H[mark] = 1;
			ans--;
		}
		if (pok[0] == 'S'){
			if (S[mark] == 1){
				continue;
			}
			S[mark] = 1;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}







//别忘了删freopen**************** 
//最后检查文件 
