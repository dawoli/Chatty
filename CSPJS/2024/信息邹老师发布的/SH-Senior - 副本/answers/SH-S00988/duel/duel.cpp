#include <bits/stdc++.h>
using namespace std;

int r[100009];

int main(){
	int n;
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		int x;
		cin >> x;
		r[x] ++;
	}
	//sort(r + 1 , r + n + 1);
	int rest = 0 , killed = 0;
	rest = r[1];
	for(int i = 2 ; i <= 100009 ; i ++){
		if(r[i] > rest){
			//rest = 0;
			killed += rest;
		    rest = r[i];// - rest;
		}
		else if(r[i] == rest){
			killed += rest;
			rest = r[i];
		}
		else{
			killed += r[i];
			rest = rest;// - r[i];
		}
	}
	cout << n - killed;


	return 0;
}

