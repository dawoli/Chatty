#include<bits/stdc++.h>
using namespace std;
int T, ans;
string s[55], temp;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i++){
	    cin >> temp;
	    s[i] = temp;
	    for (int j = 1; j < i; j++){
	    	if (s[j] == temp)
	    	   ans++;
		}
	}
	cout << 52 + ans - T;
}
