#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
map <string, bool> a;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n, cnt = 52;
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		if(a[s] == false){
			cnt--;
			a[s] = true;
		}
		else{
			a[s] = true;
		}
	}
	cout << cnt;
	return 0;
}
