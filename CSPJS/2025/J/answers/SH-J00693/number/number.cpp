#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int j = 0;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++){
		if(isdigit(s[i])) a[j++] = int(s[i] - '0');
	}
	sort(a, a + j, cmp);
	for(int i = 0; i < j; i++) cout << a[i];
	return 0;
}
