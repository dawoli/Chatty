#include <bits/stdc++.h>
using namespace std;

int n;
int card[100010];
int ans = 0;

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	int t;
	for (int i = 0; i < n; i++){
		scanf("%d", &t);
		card[t]++;
	}
	t = 0;
	for (int i = 0; i < 100009; i++){
		t = t > card[i] ? t : card[i];
	}
	cout << t;
}
