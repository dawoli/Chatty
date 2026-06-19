#include<bits/stdc++.h> 

int a[11] = {6,2,5,5,4,5,6,3,7,6};
int b[11];

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	std::cin >> T;
	int n[51];
	int nn;
	bool out = 0;
	for (int i = 1; i <= T; i++){
		std::cin >> n[i];
		if (n[i] <= 7) {
			for (int j = 1; j <= 9; j++){
				if (a[j] == n[i]) {
					std::cout << j;
					out = 1;
					break;
				}
			}
		} else {
			nn = n[i];
			for (int j = 1; nn > 7; j++){
				nn -= 7;
				b[8]++;
			}
			if (b[8] >= 2 && nn != 0) {
				for (int j = 1; j <= b[8] / 2; j++){
					b[8]--;
					b[0]++;
					nn++;
				}
			}
			for (int j = 1; j <= 9; j++){
				if (a[j] == nn) {
					b[j]++;
					nn -= a[j];
					break;
				}
			}
			for (int j = 1; j <= 9; j++){
				if (b[j] >= 1) {
					std::cout << j;
					b[j]--;
					out = 1;
					break;
				}
			}
			for (int j = 0; j <= 9; j++){
				for (int k = 0; k < b[j]; k++){
					std::cout << j;
					out = 1;
				}
			}
		}
		if (out == 0 || nn != 0) std::cout << -1;
		std::cout << std::endl;
	}
	return 0;
}

