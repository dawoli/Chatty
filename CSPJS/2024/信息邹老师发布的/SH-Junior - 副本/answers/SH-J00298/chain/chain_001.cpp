#include <bits/stdc++.h>
using namespace std;
bool luck(int x){
	return ((x*x ^ 'c')/27) % 2;
}
bool luck2(int x){
	return ((x*x ^ 'f')/461) % 2;
}
int n;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout); 
	cin >> n;
	if(n % 3 != 2){
		for(int i = 1; i <= n; ++ i){
			cout << luck(i) << endl;
		}
	}
	else{
		for(int i = 1; i <= n; ++ i){
			cout << luck2(i) << endl;
		}
	}
	return 0;
}
