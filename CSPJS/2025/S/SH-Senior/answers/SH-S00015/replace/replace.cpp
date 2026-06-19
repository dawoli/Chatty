#include<fstream>

int main()
{
	std::ifstream fin("replace.in");
	std::ofstream fout("replace.out");
	
	int a, b;
	fin >> a >> b;
	for(int i = 1; i <= b; ++i)
		fout << 0 << "\n";
}
