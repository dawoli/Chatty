#include <bits/stdc++.h>
using namespace std;
//int s[10] = {6,2,5,5,4,6,3,7,6};
int check(long long n){
	if(n == 2){
		return 1;
	}else if(n == 3){
		return 7;
	}else if(n == 4){
		return 4;
	}else if(n == 5){
		return 2;
	}else if(n == 6){
		return 6;
	}else if(n == 7){
		return 8;
	}else if(n == 9){
		return 81;
	}else if(n == 10){
		return 32;
	}else if(n == 12){
		return 82;
	}else if(n == 13){
		return 86;
	}else{
		return 0;
	}
}
void operate(long long n){
	string s = "";
	while(n >= 14){
		n -= 7;
		s  += '8';
	}
	if(n == 8){
		s += "01";
	}else if(n == 11){
		s += "02";
	}else{
		int t = check(n);
		string st = to_string(t);
		s += st;
	}
	reverse(s.begin(),s.end());
	cout << s << endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		long long k;
		cin >> k;
		if(k % 7 == 0){
			while(k){
				cout << 8;
				k -= 7;
			}
		}else if(k == 1){
			cout << -1 << endl;
		}else{
			operate(k);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
