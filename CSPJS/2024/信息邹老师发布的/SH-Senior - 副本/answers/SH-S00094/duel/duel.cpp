#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1; 
bool dueled[N];
bool failed[N];

bool cmp(int a, int b) {
	return a < b;
}
/*
int main() {
	freopen("duel.in", "r", stdin);
	//freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	
	int powers[n+1];
	for (int i = 1; i <= n; i++) {
		cin >>powers[i];
	}
	
	sort(powers+1, powers+1+n, cmp);
	// out:5s 
	
	int count = n;
	for (int i = 1; i <= n; i++) {
		if (dueled[i] == true) {
			continue;
		}
		
		for (int j = i + 1; j <= n; j++) {
			if (powers[i] < powers[j] && dueled[j] == false) {
				dueled[j] = true;
				count--;
				break;
			}
		}
	}
	
	cout << count;
	return 0;
}
*/

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	
	int powers[n+1];
	for (int i = 1; i <= n; i++) {
		cin >>powers[i];
	}
	
	sort(powers+1, powers+1+n, cmp);
	
	int count = n;
	for (int i = 2; i <= n; i++) {
		if (dueled[i] == true || failed[i] == true) {
			continue;
		}
		
		for (int j = 1; j < i; j++) {
			if (powers[i] > powers[j] && failed[j] == false) {
				dueled[i] = true;
				failed[j] = true;
				count--;
				break;
			}
		}
	}
	
	cout << count;
	return 0;
}

