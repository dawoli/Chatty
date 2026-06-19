#include <iostream>
#include <algorithm>
using namespace std;
int n = 0, ans = 0;
struct mon{
	int r;
	bool att;
}a[100010];
bool cmp(mon a, mon b) {
	return a.r < b.r;
}
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].r;
		a[i].att = false;
	}
	sort(a, a + n, cmp);
	/*
	for(int i = 0; i < n; i++) {
		cout << a[i].r << " ";
	}
	cout << endl;*/
	for(int i = 0; i < n; i++) {
		int idx = 0;
		for(int j = i; j < n; j++) {
			if(a[j].r > a[i].r && a[j].att == false) {
				idx = j;
				break;
			}
		}
		//cout << idx << endl;
		if(idx != 0) {
			a[idx].att = true;
			a[i].r = 0;
		}
	}
	for(int i = 0; i < n; i++) {
		if(a[i].r > 0) {
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
