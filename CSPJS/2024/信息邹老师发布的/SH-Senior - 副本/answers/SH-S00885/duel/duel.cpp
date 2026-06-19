#include <iostream>
using namespace std;

int main(void) {
	int n=0, count[100100] = {0}, alive=0;
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int in=0, i=0;i<n;i++) {
		cin >> in;
		count[in]++;
	}
	for (int i=1;i<=100000;i++)
	    if (alive < count[i])
	        alive = count[i];
	cout << alive << endl;
	return 0;
}
