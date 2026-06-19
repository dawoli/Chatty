#include<bits/stdc++.h>
using namespace std;
#define ll long long
//ten year's OI all in vain , no long long see forefathers
ll T , n;
string s;
string f(ll a){
	s = "";
	if(a == 1) return "-1";
	ll k = a % 7;
	if(k == 0){
		for(int i = 0 ; i < a / 7 ; i++) s = s + '8';
		return s;
	}
	if(k == 1){
		s = "10";
		for(int i = 1 ; i < a / 7 ; i++) s = s + '8';
		return s;
	}
	if(k == 2){
		s = "1";
		for(int i = 0 ; i < a / 7 ; i++) s = s + '8';
		return s;
	}
	if(k == 3){
		if(a == 3) return "7";
		else if(a == 10) return "22";
		else{
			s = "200";
			for(int i = 2 ; i < a / 7 ; i++) s = s + '8';
			return s;
		}
	}
	if(k == 4){
		if(a == 4) return "4";
		s = "20";
		for(int i = 1 ; i < a / 7 ; i++) s = s + '8';
		return s;
	}
	if(k == 5){
		s = "2";
		for(int i = 0 ; i < a / 7 ; i++) s = s + '8';
		return s;
	}
	if(k == 6){
		s = "6";
		for(int i = 0 ; i < a / 7 ; i++) s = s + '8';
		return s;
	}
}
int main(){
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	cin >> T;
	for(int I = 0 ; I < T ; I++){
		cin >> n;
		cout << f(n) << "\n";
	}
}
