#include <bits/stdc++.h>
using namespace std;

int t;
long long f[100005];
int w(int x){
	int ans = 0;
	int p = 1;
	if(x == 0) return 1;
	while(p <= x){
		p *= 10;
		ans++;
	}
	return ans;
}

void init(){
	f[2] = 1;
	f[3] = 7;
	f[4] = 4;
	f[5] = 2;
	f[6] = 6;
	f[7] = 8;
	for(int i = 8; i < 100000; i++){
		f[i] = 0x3f3f3f3f;
		for(int j = 2; j <= 7; j++){
			long long p = f[i - j];
			int wei = w(p);
			long long ten = pow(10, wei);
			f[i] = min(f[i], p + f[j] * ten);
		} 
	}
} 

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	init();
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n == 1) cout << -1 << endl;
		/*else if(n == 2) cout << 1 << endl;
		else if(n == 3) cout << 7 << endl;
		else if(n == 4) cout << 4 << endl;
		else if(n == 5) cout << 2 << endl;
		else if(n == 6) cout << 6 << endl;
		else if(n == 7) cout << 8 << endl;
		else if(n == 8) cout << 10 << endl;
		else if(n == 9) cout << 18 << endl;
		else if(n == 10) cout << 22 << endl;
		else if(n == 11) cout << 20 << endl;
		else if(n == 12) cout << 27 << endl;
		else if(n == 13) cout << 68 << endl;
		else if(n == 14) cout << 88 << endl;
		else if(n == 15) cout << 108 << endl;
		else if(n == 16) cout << 180 << endl;
		else if(n == 17) cout << 227 << endl;
		else if(n == 18) cout << 208 << endl;
		else if(n == 19) cout << 288 << endl;
		else if(n == 20) cout << 688 << endl;*/
		else{
			long long m = f[n];
			long long wei = w(m);
			for(int i = 1; i <= wei; i++){
				long long a1 = pow(10, i - 1);
				long long a2 = pow(10, wei - i);
				long long an = m / a1;
				an = an % a2;
				if(an == 6){
					m -= 6 * a1;
				}
			}
			cout << m << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
