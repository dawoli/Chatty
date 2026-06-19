#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[500005];
long long phead, ptail;

int check(int s, int e){
	int ans = 0;
	for(phead = s; phead < e; phead ++){
		for(ptail = phead + 1; ptail <= e; ptail++){
			long long xors = a[phead-1] ^ a[ptail-1];
//			cout << phead << " " << ptail << " " << xors << ";" << endl;
			if(xors == k){
				if((ptail - phead) > 3){
//					cout << "call " << phead+1 << " " << ptail << ";" << endl;
					int t = check(phead + 1, ptail);
//					cout << "ret " << t << endl;
					if(t>1){
						ans += t-1;
					}	
				}
//				cout << "ok;" << endl;
				ans++;
				phead = ptail - 1;
				break;
			}
		}	
	}
	return ans;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] ^= a[i-1];
	}
	
	int ans = check(0, n+1);
	
	cout << ans;
	
	return 0;
}
