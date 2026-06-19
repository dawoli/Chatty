#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("poker.in");
ofstream fout("poker.out");
bool d[15], c[15], h[15], s[15];
int ans;
int main() {
	int n;
	fin >> n;
	for (int i = 1; i <= n; ++i) {
		char x, card;
		fin >> x >> card;
		if (x == 'D') {
			if (card >= '2' && card <= '9') d[card - '0'] = 1;
			else if (card == 'A') d[1] = 1;
			else if (card == 'T') d[10] = 1;
			else if (card == 'J') d[11] = 1;
			else if (card == 'Q') d[12] = 1;
			else if (card == 'K') d[13] = 1;
		}
		else if (x == 'C') {
			if (card >= '2' && card <= '9') c[card - '0'] = 1;
			else if (card == 'A') c[1] = 1;
			else if (card == 'T') c[10] = 1;
			else if (card == 'J') c[11] = 1;
			else if (card == 'Q') c[12] = 1;
			else if (card == 'K') c[13] = 1;
		}
		else if (x == 'H') {
			if (card >= '2' && card <= '9') h[card - '0'] = 1;
			else if (card == 'A') h[1] = 1;
			else if (card == 'T') h[10] = 1;
			else if (card == 'J') h[11] = 1;
			else if (card == 'Q') h[12] = 1;
			else if (card == 'K') h[13] = 1;
		}
		else if (x == 'S') {
			if (card >= '2' && card <= '9') s[card - '0'] = 1;
			else if (card == 'A') s[1] = 1;
			else if (card == 'T') s[10] = 1;
			else if (card == 'J') s[11] = 1;
			else if (card == 'Q') s[12] = 1;
			else if (card == 'K') s[13] = 1;
		}
	}
	for (int i = 1; i <= 13; ++i) {
		if (!d[i]) ++ans;
		if (!c[i]) ++ans;
		if (!h[i]) ++ans;
		if (!s[i]) ++ans;
	} 
	fout << ans << "\n"; 
	return 0;
} 
