#include<bits/stdc++.h>
using namespace std;

int n;
string poker[53];
int ans = 51;

bool check(string s, int p){
	for(int i = 1;i < p;i++){
		if(poker[i] == s){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	cin >> n;
	
	for(int i = 1;i <= n;i++){
		cin >> poker[i];
		if(check(poker[i], i) && i != 1) ans--;
	}
	
	cout << ans << endl;
	return 0;
} 
