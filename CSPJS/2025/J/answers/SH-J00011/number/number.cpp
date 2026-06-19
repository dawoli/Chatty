#include <bits/stdc++.h>
using namespace std;
int nums[100];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s; cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			nums[s[i] - '0']++; 
		}
	}
	for (int i = 9; i >= 0; i--){
		while (nums[i] != 0){
			cout << i;
			nums[i]--;
		}
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
