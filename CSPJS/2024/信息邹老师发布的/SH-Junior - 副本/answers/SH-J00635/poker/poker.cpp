#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	set <string> s;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		string x;
		cin >> x;
		s.insert(x);
	}
	cout << 52 - s.size();
	return 0;
} 
