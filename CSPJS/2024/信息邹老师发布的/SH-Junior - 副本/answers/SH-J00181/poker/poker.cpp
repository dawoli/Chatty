#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","W",stdout);
	int n;
	cin >> n;
	while(n--){
		int x,weishu;
		cin >> x;
		if(x % 7 == 0) weishu = x/7;
		else weishu = x/7+1;
		cout << weishu; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
