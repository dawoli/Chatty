#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int b[53] = {0};//1-13D 14-26C 27-39H 40-52S
	int n;
	cin >> n;
	char c[3];
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> c;
		if(c[0] == 'D'){
			tmp = 0;
		}else if(c[0] == 'C'){
			tmp = 13;
		}else if(c[0] == 'H'){
			tmp = 26;
		}else{
			tmp = 39;
		}
		if(c[1] == 'A'){
			tmp += 1;
		}else if(c[1] == 'T'){
			tmp += 10;
		}else if(c[1] == 'J'){
			tmp += 11;
		}else if(c[1] == 'Q'){
			tmp += 12;
		}else if(c[1] == 'K'){
			tmp += 13;
		}else{
			tmp += int(c[1] - '0');
		}
		b[tmp] = 1;
	}
	int ans = 52;
	
	for(int i = 1; i <= 52; i++){
		ans -= b[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
