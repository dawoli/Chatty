#include<bits/stdc++.h>
using namespace std;

int D[14];
int C[14];
int H[14];
int S[14];

string Input;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int N;
	scanf("%d", &N);
	int Sum = 0;
	
	for (int i = 1; i <= N; i++) {
		cin >> Input;
		
		int Numint;
		if (Input[1] == 'A') {
			Numint = 1;
		} else if (Input[1] == 'T') {
			Numint = 10;
		} else if (Input[1] == 'J') {
			Numint = 11;
		} else if (Input[1] == 'Q') {
			Numint = 12;
		} else if (Input[1] == 'K') {
			Numint = 13;
		} else {
			Numint = int(Input[1] - '0');
		}
		
		if (Input[0] == 'D') {
			D[Numint] += 1;
			if (D[Numint] > 1) {
				Sum += 1;
			}
		} else if (Input[0] == 'C') {
			C[Numint] += 1;
			if (C[Numint] > 1) {
				Sum += 1;
			}
		} else if (Input[0] == 'H') {
			H[Numint] += 1;
			if (H[Numint] > 1) {
				Sum += 1;
			}
		} else if (Input[0] == 'S') {
			S[Numint] += 1;
			if (S[Numint] > 1) {
				Sum += 1;
			}
		}
	}
	
	printf("%d", 52 - N + Sum);
	 
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
} 
