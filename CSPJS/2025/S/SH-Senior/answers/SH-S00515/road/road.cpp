#include<bits/stdc++.h>
using namespace std;

struct note{
	long long x, y;
	long long z;
}a[1000005];

bool cmp(note d, note e){
	return d.z < e.z;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long ans = 0;
	long long kt[15][10005] = {};
	long long kc[15] = {};
	long long n, m, k;
	cin >> n >> m >> k;
	for(long long i = 0;i < m;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	for(long long i = 0;i < k;i++){
		cin >> kc[i];
		for(long long j = 0;j < n;j++){
			cin >> kt[i][j];
		}
	}
	int abcd = m;
	for(long long i = m;i < k + m;i++){
		for(long long j = 1;j <= n;j++){
			for(long long abc = j;abc <= n;abc++){
				a[abcd].x = j;
				a[abcd].y = abc;
				a[abcd].z = kt[i - m][j]+ kc[i - m]+kt[i - m][abc];
				abcd++;
			}
		}
	}
	sort(a, a + abcd, cmp);
	//ceshi
	//for(int i =0;i < 100;i++){
	//	cout << a[i].z << " " << a[i].x << " " << a[i].y << endl;
	//}
	bool s[10005][10005] = {};
	for(long long i = 0;i < n;i++){
			ans += a[i].z;
			s[a[i].x][a[i].y] = true;
			s[a[i].y][a[i].x] = true;
	}
	cout << ans << endl;
	return 0;
}
