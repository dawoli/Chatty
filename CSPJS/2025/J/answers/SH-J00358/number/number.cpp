#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	if (s.size() <= 1 && s[0] >= '0' && s[0] <= '9'){
		cout << s;
		return 0;
	}
	
	else {
		int a[15] = {0};
		for (int i = 0; i < s.size(); i++){
			
			if (s[i] >= '0' && s[i] <= '9'){
//				int(s[i]);
				int b = s[i] - '0';
				a[b] += 1;
			}
		}
		
		//shuchu
		for (int i = 9; i >= 0; i--){
			for (int j = 1; j <= a[i]; j++){
				cout << i;
			}
		}
		return 0;
	}
	
	return 0;
}
