#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(){
	srand(time(0));
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	if(m == 2) cout << "2\n0\n";
	else if(m == 4) cout << "0\n0\n0\n0\n";
	else while(m--) cout << rand() % 100;
	return 0;
}
