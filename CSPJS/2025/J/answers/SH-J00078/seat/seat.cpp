#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, f;
	scanf("%d %d", &n, &m);
	vector<int> v(n * m);
	for(int i=0; i<n*m; i++) {
		scanf("%d", &v[i]);
	}
	f = v[0];
	sort(v.begin(), v.end(), cmp);
	int flag = 0;
	int a[17][17];
	int hang, lie;
	hang = lie = 0;
	for(int i=0; i<n*m; i++) {
		a[hang][lie] = v[i];
		if(v[i] == f) {
			printf("%d %d\n", lie + 1, hang + 1);
			break;
		}
		if(flag == 0) {
			hang ++;
			if(hang == n - 1) {
				flag = 2;
			}
		}
		else if(flag == 1) {
			hang --;
			if(hang == 0) {
				flag = 2;
			}
		}
		else {
			lie ++;
			if(hang == 0) {
				flag = 0;
			}
			else {
				flag = 1;
			}
		}
	}
	return 0;
}
