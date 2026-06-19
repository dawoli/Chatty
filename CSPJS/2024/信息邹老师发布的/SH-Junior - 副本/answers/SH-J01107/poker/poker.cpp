#include<bits/stdc++.h> 

int a[5][14]; 

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	std::cin >> n;
	std::string aa;
	int ans = 52;
	for(int i = 1; i <= n; i++){
		std::cin >> aa;
		if (aa[0] == 'D') {
			if (aa[1] == '1') a[1][1]++;
			else if (aa[1] == '2') a[1][2]++;
			else if (aa[1] == '3') a[1][3]++;
			else if (aa[1] == '4') a[1][4]++;
			else if (aa[1] == '5') a[1][5]++;
			else if (aa[1] == '6') a[1][6]++;
			else if (aa[1] == '7') a[1][7]++;
			else if (aa[1] == '8') a[1][8]++;
			else if (aa[1] == '9') a[1][9]++;
			else if (aa[1] == 'T') a[1][10]++;
			else if (aa[1] == 'J') a[1][11]++;
			else if (aa[1] == 'Q') a[1][12]++;
			else a[1][13]++;
		} else if (aa[0] == 'C') {
			if (aa[1] == '1') a[2][1]++;
			else if (aa[1] == '2') a[2][2]++;
			else if (aa[1] == '3') a[2][3]++;
			else if (aa[1] == '4') a[2][4]++;
			else if (aa[1] == '5') a[2][5]++;
			else if (aa[1] == '6') a[2][6]++;
			else if (aa[1] == '7') a[2][7]++;
			else if (aa[1] == '8') a[2][8]++;
			else if (aa[1] == '9') a[2][9]++;
			else if (aa[1] == 'T') a[2][10]++;
			else if (aa[1] == 'J') a[2][11]++;
			else if (aa[1] == 'Q') a[2][12]++;
			else a[2][13]++;
		} else if (aa[0] == 'H') {
			if (aa[1] == '1') a[3][1]++;
			else if (aa[1] == '2') a[3][2]++;
			else if (aa[1] == '3') a[3][3]++;
			else if (aa[1] == '4') a[3][4]++;
			else if (aa[1] == '5') a[3][5]++;
			else if (aa[1] == '6') a[3][6]++;
			else if (aa[1] == '7') a[3][7]++;
			else if (aa[1] == '8') a[3][8]++;
			else if (aa[1] == '9') a[3][9]++;
			else if (aa[1] == 'T') a[3][10]++;
			else if (aa[1] == 'J') a[3][11]++;
			else if (aa[1] == 'Q') a[3][12]++;
			else a[3][13]++;
		} else {
			if (aa[1] == '1') a[4][1]++;
			else if (aa[1] == '2') a[4][2]++;
			else if (aa[1] == '3') a[4][3]++;
			else if (aa[1] == '4') a[4][4]++;
			else if (aa[1] == '5') a[4][5]++;
			else if (aa[1] == '6') a[4][6]++;
			else if (aa[1] == '7') a[4][7]++;
			else if (aa[1] == '8') a[4][8]++;
			else if (aa[1] == '9') a[4][9]++;
			else if (aa[1] == 'T') a[4][10]++;
			else if (aa[1] == 'J') a[4][11]++;
			else if (aa[1] == 'Q') a[4][12]++;
			else a[4][13]++;
		} 
	}
	for(int i = 1; i <= 5; i++){
		for (int j = 1; j <= 14; j++){
			if (a[i][j] > 0) ans--; 
		}
	}
	std::cout << ans;
	return 0;
}

