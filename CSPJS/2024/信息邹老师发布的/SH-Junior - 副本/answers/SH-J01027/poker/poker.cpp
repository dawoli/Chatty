#include<bits/stdc++.h>
using namespace std;

string a[5] = {"", "D", "C", "H", "S"};
string b[14] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};

map<string, int> m; // mapÕæºÃÓÃ

int n, ans;
string tmp;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>tmp;
		m[tmp] = 1;
	}
	for(int i=1; i<=4; i++){
		for(int j=1; j<=13; j++){
			tmp = a[i] + b[j];
			if(m[tmp] == 1) ans++;
		}
	}
	cout<<(52 - ans); 
	return 0;
}
