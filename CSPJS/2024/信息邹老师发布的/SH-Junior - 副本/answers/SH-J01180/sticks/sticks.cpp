#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, pos;
string a[1919810];
string f[1919810];
string cal(string x, string y){
	for(int i = 0; i < x.length(); i++){
		a[i] = x[i];
	}
	a[x.length()] = y;
	sort(a, a + x.length() + 1);
	for(int i = 0; i <= x.length(); i++){
		if(a[i] != "0"){
			pos = i;
			break;
		}
	}
	if(pos != 0){
		swap(a[pos], a[0]);
	}
	string ans;
	for(int i = 0; i <= x.length(); i++){
		ans = ans + a[i];
	}
	return ans;
}
string mimn(string a, string b){
	if(a == "aaa"){
		return b;
	}
	if(a.length() < b.length()){
		return a;
	} else if(a.length() > b.length()){
		return b;
	} else{
		for(int i = 0; i < a.length(); i++){
			if(a[i] < b[i]){
				return a;
			} else if(b[i] < a[i]){
				return b;
			}
		}
	}
	return a;
}
signed main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	for(int i = 1; i <= 1145; i++){
		f[i] = "aaa";
	}
	f[0] = "-1";
	f[1] = "-1";
	f[2] = "1";
	f[3] = "7";
	f[4] = "4";
	f[5] = "2";
	f[6] = "6";
	f[7] = "8";
	for(int i = 8; i <= 1145; i++){
		if(f[i - 6] != "-1"){
			f[i] = mimn(f[i], cal(f[i - 6], "0"));
		}
		if(f[i - 2] != "-1"){
			f[i] = mimn(f[i], cal(f[i - 2], "1"));
		}
		if(f[i - 5] != "-1"){
			f[i] = mimn(f[i], cal(f[i - 5], "2"));
		}
		if(f[i - 4] != "-1"){
			f[i] = mimn(f[i], cal(f[i - 4], "4"));
		}
		if(f[i - 3] != "-1"){
			f[i] = mimn(f[i], cal(f[i - 3], "7"));
		}
		if(f[i - 7] != "-1"){
			f[i] = mimn(f[i], cal(f[i - 7], "8"));
		}
		if(f[i] == "aaa"){
			f[i] = "-1";
		}
	}
	cin >> t;
	while(t--){
		cin >> n;
		if(n % 7 == 0){
			for(int i = 7; i < n; i += 7){
				cout << 8;
			}
			puts("");
			continue;
		} else if((n - 1) % 7 == 0){
			printf("10");
			for(int i = 1; i < n - 2; i += 7){
				printf("8"); 
			} 
			puts("");
			continue;
		}
		cout << f[n] << "\n";
	}
	return 0;
}
