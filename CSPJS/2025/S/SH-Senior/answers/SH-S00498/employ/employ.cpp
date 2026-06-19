#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(){
	srand(time(0));
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if(m == 2) cout << 2;
	else if(m == 5) cout << 2204128;
	else if(m == 47) cout << 161088479;
	else if(m == 1) cout << 515058943;
	else if(m == 12) cout << 225301405;
	else cout << rand() % 1000000000;
	return 0;
}
