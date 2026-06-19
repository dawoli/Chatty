#include <bits/stdc++.h>
using namespace std;

//0 1 2 3 4 5 6 7 8 9
//6 2 5 5 4 5 6 3 7 6

int T;
int solve(int x) {
	if (x == 1) return -1;
	if (x == 2) return 1;
	if (x == 3) return 7;
	if (x == 4) return 4;
	if (x == 5) return 2;
	if (x == 6) return 6;
	if (x == 7) return 8;
	return -1;
}

int main() {
	freopen("sticks.in.txt", "r", stdin);
	freopen("sticks.out.txt", "w", stdout);
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n; scanf ("%d", &n);
		int x = n % 7, y = n / 7;
		if (n <= 7){
			printf ("%d\n", solve(n));
			continue;
		}
		if (x == 0) {
			for (int i = 1; i <= y; i++)
				printf ("8");
			printf ("\n"); continue;
		}
		if (x == 1) {
			printf ("10");
			for (int i = 1; i <= y - 1; i++)
				printf ("8");
			printf ("\n"); continue;
		}
		if (x == 2) {
			printf ("18");
			for (int i = 1; i <= y - 1; i++)
				printf ("8");
			printf ("\n"); continue;
		}
		if (x == 3) {
			printf ("23");
			for (int i = 1; i <= y - 1; i++)
				printf ("8");
			printf ("\n"); continue;
		}
		if (x == 4) {
			printf ("20");
			for (int i = 1; i <= y - 1; i++)
				printf ("8");
			printf ("\n"); continue;
		}
		if (x == 5) {
			printf ("28");
			for (int i = 1; i <= y - 1; i++)
				printf ("8");
			printf ("\n"); continue;
		}
		if (x == 6) {
			printf ("68");
			for (int i = 1; i <= y - 1; i++)
				printf ("8");
			printf ("\n"); continue;
		}
	}
	//printf ("Time : %d\n", clock());
	return 0;
}
