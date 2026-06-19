#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	int a[100005];
	memset(a,-1,sizeof(a));
	a[1] = -1;a[2] = 1;a[3] = 7;a[4] = 4;a[5] = 2;a[6] = 6;a[7] = 8;
	while (T--){
		int n;
		cin >> n;
		if (n <= 7)
			cout << a[n] << endl;
		else{
			if (n % 7 == 0) 
				for (int i = 1;i <= n/7;i++)
					cout << 8;
			else{
				cout << 10;
				for (int i = 1;i <= n/7 - 1;i++) cout << 8;
			}
			cout << endl;
		} 
	}
	return 0;
}
