#include<bits/stdc++.h>
using namespace std;

//GL@17SXYZ
//Y#C*GF@24

bool pok[100000];
int ans, n = 0;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		string x;
		cin >> x;
		int index = 0;
		if(x[0] == 'D'){
			index += 100;
		}else if(x[0] == 'C'){
			index += 200;
		}else if(x[0] == 'S'){
			index += 300;
		}else if(x[0] == 'H'){
			index += 400;
		}
		int ap = x[1] - '0';
		index += ap;
		if(pok[index] == 0){
			pok[index] = 1;
			ans ++;
		}
	}
	cout << 52 - ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
