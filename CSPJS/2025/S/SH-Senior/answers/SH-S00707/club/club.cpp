#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+40;
int a[N][5], n, t, b[N], cc[N];
//struct ccu{
//	int cha, sma, big;
//}cc[N];
//
//bool cmpa(ccu x, ccu y){
//	return x.cha < y.cha;
//}
long long sum;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while(t--){
//		cout << t << " 1111\n";
		sum = 0; b[1] = 0; b[2] = 0; b[3] = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] > a[i][2]){
				if(a[i][3] > a[i][1]){
					b[3]++; sum += a[i][3];
				}else{
					b[1]++; sum += a[i][1];
				}
			}else{
				if(a[i][3] > a[i][2]){
					b[3]++; sum += a[i][3];
				}else{
					b[2]++; sum += a[i][2];
				}
			}
		}
		int tot = 0;
		if(b[2] > n/2){
//			cout << "222 ";
//			sum = 0;
			for(int i = 1; i <= n; i++){
				if(a[i][2] >= max(a[i][1], a[i][3]))	cc[++tot] = a[i][2]-max(a[i][1], a[i][3]);
			}
			sort(cc+1, cc+tot+1);
//			for(int i = 1; i <= tot; i++) cout << cc[i] << "\n";
			for(int i = 1; i <= tot-n/2; i++){
				sum -= cc[i];
			}
			cout << sum << "\n";
			continue;
		}
		if(b[1] > n/2){
//			cout << "111 ";
			for(int i = 1; i <= n; i++){
				if(a[i][1] >= max(a[i][2], a[i][3]))	cc[++tot] = a[i][1]-max(a[i][2], a[i][3]);
			}
			sort(cc+1, cc+tot+1);
			for(int i = 1; i <= tot-n/2; i++){
				sum -= cc[i];
			}
			cout << sum << "\n";
			continue;
		}
		if(b[3] > n/2){
//			cout << " 333 ";
			for(int i = 1; i <= n; i++){
				if(a[i][3] >= max(a[i][1], a[i][2]))	cc[++tot] = a[i][3]-max(a[i][1], a[i][2]);
			}
			sort(cc+1, cc+tot+1);
			for(int i = 1; i <= tot-n/2; i++){
				sum -= cc[i];
			}
			cout << sum << "\n";
			continue;
		}
		cout << sum << "\n";
	}
	return 0;
}
