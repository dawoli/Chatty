#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nsddd;
int cnsft = 0;
map<string, bool> setooioo;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> nsddd;
	for (int i = 1; i <= nsddd; i++){
		string stril;
		cin >> stril;
		if (setooioo[stril] != 1){
			cnsft++;
			setooioo[stril] = 1;
		}
	}
	cout << 52 - cnsft;
	return 0;
} 
