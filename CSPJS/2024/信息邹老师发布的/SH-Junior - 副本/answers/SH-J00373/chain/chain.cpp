#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("chain.in");
ofstream fout("chain.out");
int main(){
	int t;
	fin >> t;
	int n;
	fin >> n;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1) fout << 1 << "\n";
		else fout << 0 << "\n";
	}
	return 0;
}
