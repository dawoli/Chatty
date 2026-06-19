#include <bits/stdc++.h>
using namespace std;
string s;
int box_number[10];
//bool compare(int x, int y) {return x > y;} 
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> s;
	int len = s.length(); 
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int int_number = s[i] - '0';
			box_number[int_number]++;
//			cout << int_number << endl;
//			cout << "----" << box_number[int_number] << endl; 
		} 
	}
//	for (int i = 0; i <= 9; i++) cout << box_number[i] << endl; 
//	sort(number + 1, number + tot, compare);
	for (int i = 9; i >= 0; i--) 
		while (box_number[i]--) printf("%d", i);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
