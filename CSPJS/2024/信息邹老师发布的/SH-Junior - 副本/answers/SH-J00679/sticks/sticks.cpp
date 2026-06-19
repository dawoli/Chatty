#include<bits/stdc++.h>
using namespace std;
int t,n,a[10]= {6,2,5,5,4,5,6,3,7,6},db[57]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888,18888888,20088888,20888888,28888888,68888888,88888888};
int cnt(int x) {
	int ans=0;
	while(x) {
		ans += a[x%10];
		x /= 10;
	}
//	cout << ans << endl;
	return ans;
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n;
		if(n >= 1 && n <= 55){
			cout << db[n] << endl;
		}
		else if(n >= 56 && n <= 1000) {
			bool flg = false;
			for(int i = 56; i <= 88888888; i++) {
				if(cnt(i) == n) {
					cout << i << endl;
					flg = true;
					break;
				}
			}
			if(!flg)	cout << "-1" << endl;
		} else {
			cout << "-1" << endl;
		}
	}
	return 0;
}
