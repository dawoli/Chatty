#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N], k = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++k] = s[i] - '0';
		}
	}
	sort(a + 1, a + k + 1);
	for(int i = k; i >= 1; i--) cout << a[i];
	cout << endl;
	return 0;
} 
