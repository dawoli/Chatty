#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string v;
	int n,a[5][15] = {{0}},c = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> v;
		if(v[0] == 'D'){
			if(v[1] >= '2' && v[1] <= '9') a[0][v[1]-'1'] = 1;
			if(v[1] == 'A') a[0][0] = 1;
			if(v[1] == 'T') a[0][9] = 1;
			if(v[1] == 'J') a[0][10] = 1;
			if(v[1] == 'Q') a[0][11] = 1;
			if(v[1] == 'K') a[0][12] = 1;
		}
		if(v[0] == 'C'){
			if(v[1] >= '2' && v[1] <= '9') a[1][v[1]-'1'] = 1;
			if(v[1] == 'A') a[0][0] = 1;
			if(v[1] == 'T') a[1][9] = 1;
			if(v[1] == 'J') a[1][10] = 1;
			if(v[1] == 'Q') a[1][11] = 1;
			if(v[1] == 'K') a[1][12] = 1;
		}
		if(v[0] == 'H'){
			if(v[1] >= '2' && v[1] <= '9') a[2][v[1]-'1'] = 1;
			if(v[1] == 'A') a[0][0] = 1;
			if(v[1] == 'T') a[2][9] = 1;
			if(v[1] == 'J') a[2][10] = 1;
			if(v[1] == 'Q') a[2][11] = 1;
			if(v[1] == 'K') a[2][12] = 1;
		}
		if(v[0] == 'S'){
			if(v[1] >= '2' && v[1] <= '9') a[3][v[1]-'1'] = 1;
			if(v[1] == 'A') a[0][0] = 1;
			if(v[1] == 'T') a[3][9] = 1;
			if(v[1] == 'J') a[3][10] = 1;
			if(v[1] == 'Q') a[3][11] = 1;
			if(v[1] == 'K') a[3][12] = 1;
		}
	}
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 13;j++){
			if(a[i][j] != 1) c++;
		}
	}
	cout << c;
	return 0;
} 
