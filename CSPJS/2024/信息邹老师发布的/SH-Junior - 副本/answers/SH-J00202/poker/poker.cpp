#include<bits/stdc++.h>
using namespace std;
set<string> t;
int n;string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s;
		t.insert(s);
	}
	cout << 52 - t.size(); 
	return 0;
}
