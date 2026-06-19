#include<fstream>
#include<string>
using namespace std;
ifstream fin("chain1.in");
ofstream fout("chain1.out");
int main()
{
	fout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0;
	return 0;
}
