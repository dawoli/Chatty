#include<bits/stdc++.h>
using namespace std;
#define ll long long
//ten year's OI all in vain , no long long see forefathers
bool p[4][15];
int f(char k){
	if(k == 'D') return 0;
	if(k == 'C') return 1;
	if(k == 'H') return 2;
	if(k == 'S') return 3;
}
int g(char k){
	if(k >= '2' && k <= '9'){
		int kk = k - '0';
		return kk;
	}
	else if(k == 'A') return 1;
	else if(k == 'T') return 10;
	else if(k == 'J') return 11;
	else if(k == 'Q') return 12;
	else return 13;
}
int main(){
	freopen("poker.in" , "r" , stdin);
	freopen("poker.out" , "w" , stdout);
	ll n , cnt = 52;
	char a , b;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a >> b;
		if(!p[f(a)][g(b)]){
			p[f(a)][g(b)] = true;
			cnt--;
		}
	}
	cout << cnt;
}
