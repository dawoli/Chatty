#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],tot = 0;
bool cmp(long long a, long long b){
	return a > b;
}
int main(){
	cin >> s;
	long long l = s.size();
	for(int i = 0; i < l; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++tot] = s[i] - '0';
		}
	}
	sort(a + 1, a + tot + 1, cmp);
	for(int i = 1; i <= tot; i++){
		cout << a[i];
	}
	cout << endl;
	return 0;
}

