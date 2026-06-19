#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int score, seatno, ansn, ansm;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("saet.out", "w", stdout);

	cin >> n >> m;
	cin >> score;
	seatno = 1;
	for(int i = 2; i <= m*n; i++){
		cin >> s;
		if(s > score){
			seatno++;
		}
	}
	
	ansm = seatno%n;
	if(ansm == 0){
		ansm = m;
	}
	ansn = (seatno-ansm)/n+1;
//	cout << ansm << " " << ansn << endl;
	if(ansn%2 == 0){
		ansm = m - ansm + 1;
	}
	
	cout << ansn << " " << ansm;
	
	return 0;
}
