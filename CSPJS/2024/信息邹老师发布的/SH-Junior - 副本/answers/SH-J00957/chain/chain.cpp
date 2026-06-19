#include <iostream>

using namespace std;

int a[10] = {1, 0, 1, 0, 1, 0, 0};

int main(){
	
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	for(int i = 0; i < 7; i++) cout << a[i] << endl;

	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
