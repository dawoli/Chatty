#include <bits/stdc++.h>
using namespace std;
char c[1000009];
long long cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> c;
	long long i=0;
	while(c[i] != 0){
		if(c[i] >= '0' && c[i] <= '9'){
			cnt[c[i]-'0']++;
		}
		i++;
	}
	bool f = false;
	for(int j=9; j>0; j--){
		if(cnt[j] != 0){
			f = true;
			for(i=0; i<cnt[j]; i++){
				cout << j;
			}
		}
	}
	if(f = false){
		cout << 0 << endl;
	}else{
		for(i=0; i<cnt[0]; i++){
			cout << 0;
		}
	}
	return 0;
} 
