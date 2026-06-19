#include <iostream>
#include <cmath>
using namespace std;

int box[100005];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int r;
		cin >> r;
		box[r]++;
	}
	int sum = box[1];
	for (int i = 2; i <= 1e5; i++){
		sum = max(sum - box[i], 0);
		sum += box[i];
	}
	cout << sum << endl;
	return 0;
}
