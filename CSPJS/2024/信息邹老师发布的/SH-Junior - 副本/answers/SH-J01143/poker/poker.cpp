#include <bits/stdc++.h>
using namespace std;
string s;
int n,pai[101][101],num;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s;
		if(pai[s[0]][s[1]] == 0){
			pai[s[0]][s[1]] = 1;
			num++;
		}
	}	
	cout << 52 - num;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
