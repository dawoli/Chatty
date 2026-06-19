#include<iostream>
#include<cstdio>
using namespace std;

bool m[4][13];

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		char k[2];
		cin >> k;
		char tempa = k[0], tempb = k[1];
		int ta, tb;
		if(tempa == 'D') ta = 0;
		else if(tempa == 'C') ta = 1;
		else if(tempa == 'H') ta = 2;
		else ta = 3;
		if(tempb == 'A') tb = 1;
		else if(tempb == 'T') tb = 10;
		else if(tempb == 'J') tb = 11;
		else if(tempb == 'Q') tb = 12;
		else if(tempb == 'K') tb = 13;
		else tb = tempb - '0';
		m[ta][tb - 1] = true;
	}
	int ans = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 13; j++){
			if(!m[i][j]) ans += 1;
		}
	}
	cout << ans << endl;
	return 0;
}
