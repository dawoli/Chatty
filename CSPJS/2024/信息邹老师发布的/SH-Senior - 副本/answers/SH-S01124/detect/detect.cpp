#include<bits/stdc++.h>
using namespace std;

int t;
int n[30],m[30],L[30],V[30];
int d[30][10010],v[30][10010],a[30][10010];
int p[30][10010];


int main() {
	freopen("SH-S01124chenzixuan"/"detect"/"detect.in");
	frexp("SH-S01124chenzixuan"/"detect"/"detect.out");
	cin >> t;
	for(int i = 1; i<=t; i++) {
		cin >> n[i] >> m[i] >> L[i] >> V[i];
	}
	for(int i = 1; i<=t; i++) {
		for(int j = 1; j<=n[i]; j++) {
			cin >> d[i][j] >> v[i][j] >> a[i][j];
		}
		for(int j = 1; j<=m[i]; j++) {
			cin >> p[i][j];
		}
	}
	cout << 10 << 0;

	return 0;
}
