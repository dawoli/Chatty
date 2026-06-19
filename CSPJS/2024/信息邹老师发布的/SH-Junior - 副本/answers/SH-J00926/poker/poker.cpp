# include <bits/stdc++.h>
# include <iostream>

int n, colour, num, not_checked;
bool checked[13][4];

int colour_map(char colour) {
	switch (colour) {
		case 'D': return 0;
		case 'C': return 1;
		case 'H': return 2;
		case 'S': return 3;
		default: return -1;
	}
}

int num_map(char num) {
	switch(num) {
		case 'A': return 0;
		case '2': return 1;
		case '3': return 2;
		case '4': return 3;
		case '5': return 4;
		case '6': return 5;
		case '7': return 6;
		case '8': return 7;
		case '9': return 8;
		case 'T': return 9;
		case 'J': return 10;
		case 'Q': return 11;
		case 'K': return 12;
		default: return -1;
	}
}

int main() {
	memset(checked, false, sizeof(checked));
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	scanf("%d\n", &n);
	not_checked = 52;
	for (int i = 0; i < n; i++) {
		scanf("%c%c\n", &colour, &num);
		if (!checked[num_map(num)][colour_map(colour)]) {
			not_checked--;
			checked[num_map(num)][colour_map(colour)] = true;
		}
	}
	printf("%d", not_checked);
	return 0;
} 
