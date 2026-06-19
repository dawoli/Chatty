#include <bits/stdc++.h>
using namespace std;

bool chek[114][514];
int n;
int ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	string pok;
	int cp1= 0, cp2 = 0;
	while(n--){
		cin >> pok;
		cp1 = 0;
		cp2 = 0;
		if(pok[0] == 'D'){
			cp1 = 1;
		}
		else if(pok[0] == 'C'){
			cp1 = 2;
		}
		else if(pok[0] == 'H'){
			cp1 = 3;
		}
		else if(pok[0] == 'S'){
			cp1 = 4;
		}
		if(pok[1] == 'J'){
			cp2 = 11;
		}
		else if(pok[1] == 'Q'){
			cp2 = 12;
		}
		else if(pok[1] == 'K'){
			cp2 = 13;
		}
		else if(pok[1] == 'T'){
			cp2 = 10;
		}
		else if(pok[1] == 'A'){
			cp2 = 1;
		}
		else{
			cp2 = pok[1] - '0';
		}
		chek[cp1][cp2] = true;
	}
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 13; j++){
			if(chek[i][j] == false) ans++;
		}
	}
	cout << ans;
	return 0;
}
