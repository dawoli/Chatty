#include <iostream>
#include <set>

using namespace std;

int n;
string a;
set<string> ssi;

int main(){
	
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a;
		ssi.insert(a);
	}
	
	cout << 52 - ssi.size();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
