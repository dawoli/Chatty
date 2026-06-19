#include <bits/stdc++.h>
using namespace std;
long long b[1000001];
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	string a;
	cin >> a;
	for(int i = 0;i < 1000001;i++){
		b[i] = -1;
	}
	for(int i = 0;i < a.length();i++){
		if('0' <= a[i] && a[i] <= '9')
			b[i] = a[i]-'0';
	}
	sort(b,b+a.length(),cmp);
	if(b[0] == 0){
		cout << 0;
		return 0;
	}
	int j = 0;
	while(b[j] != -1){
		cout << b[j];
		j++;
	}
	return 0;
}
