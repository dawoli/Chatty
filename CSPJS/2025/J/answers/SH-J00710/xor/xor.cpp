#include<bits/stdc++.h>

using namespace std;
const int N = 5e5+40;
int n, k;//^ÊÇÒì»ò
int a[N], s[N], q, sum;


int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	s[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1]^a[i];
//		cout << s[i] << "\n";
		for(int j = q; j < i; j++){
			if((s[i]^k) == s[j]){
				q = i;
//				cout << (s[i]^k) << " " << s[j] << " 11111\n";
				sum++;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}
