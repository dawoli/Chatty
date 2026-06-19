#include <iostream>
#include <fstream>
#define EIN fin
#define EOUT fout
using namespace std;
ifstream fin("arena.in");
ofstream fout("arena.out");
int main()
{
	ios::sync_with_stdio(0);
	EOUT<<20;
	fin.close();
	fout.close();
	return 0;
}
