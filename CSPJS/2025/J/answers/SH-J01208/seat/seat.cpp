#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	int a[110];
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int r = a[1];
	sort(a + 1,a + n*m + 1);
	int wz=0;
	for(int i = 1;i <= n*m;i++){
		if(a[i] == r){
			wz = n*m - i + 1;
			break;
		}
	}
	int lie=0;
	if(wz % n == 0){
		lie = wz / n;
		if(lie % 2 == 1){
			cout << lie << ' ' << n;
		}else{
			cout << lie << ' ' << 1;
		}
	}else{
		lie = wz / n + 1;
		if(lie % 2 == 1){
			cout << lie << ' ' << wz % n;
		}else{
			cout << lie << ' ' << n - (wz % n) + 1;
		}
	}
	return 0;
}
