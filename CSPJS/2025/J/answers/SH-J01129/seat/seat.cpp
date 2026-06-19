#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct NiuMa {
	int score,id;
	bool operator <(const NiuMa &temp)const {
		return score>temp.score;
	}
}a[1011];
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
//	cout << n << " " << m << endl;
	for(int i = 1;i <= n*m;i++) {
		cin >> a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	int direct = 0;
	for(int i = 1;i <= n*m;i++) {
		if(a[i].id==1) {
			cout << nowy << " " << nowx << endl;
			return 0;
		}
		if(direct == 0) {
			if(nowx==n) {
				direct=1;
				nowy++;
			}else nowx++;
		}else {
			if(nowx==1) {
				direct=0;
				nowy++;
			}else nowx--;
		}
	}
	return 0;
}
