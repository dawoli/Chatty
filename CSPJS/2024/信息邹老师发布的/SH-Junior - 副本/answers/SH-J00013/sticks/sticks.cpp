#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int ans[114514];
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		int i;
		for(i = 1; n >= 7; n-=7, i++){
			ans[i] = 8;
		}
		if(n == 1 && i > 2){
			ans[i-1] = 0;
			ans[i] = 2;
		}
		else i--;
		for(; i >= 1; i--){
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
