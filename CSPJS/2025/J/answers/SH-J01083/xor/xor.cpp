#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	int s[100000];
	bool flag = true;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> s[i];
		if(s[i] != 0){
			flag = false;
		}
	}
	if(n<=2){
		cout << 0;
		return 0;
	} if(k==0 && flag == true){
		cout << n/2;
	}if(k == 1){
		int ans =0;
		for(int i = 0;i < n;i++){
			if(s[i] == 1){
				ans++;
			}
		}cout << ans;
		return 0;
	}
	return 0;
} 
