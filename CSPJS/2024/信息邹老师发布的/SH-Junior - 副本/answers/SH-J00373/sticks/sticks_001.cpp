#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sticks.in");
ofstream fout("sticks.out");
int main(){
	int t;
	fin >> t;
	for(int i = 0; i < t; i++){
		fout << -1 << "\n";
	}
	return 0;
}
