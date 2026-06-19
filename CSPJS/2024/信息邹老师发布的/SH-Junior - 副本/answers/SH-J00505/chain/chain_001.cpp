#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int s = i % 2;
		cout << s << endl;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
