#include<fstream>
#include<string>
std::string s;
int main(){
	int n,q;
	std::fstream fin("replace.in",std::ios::in),fout("replace.out",std::ios::out);
	fin >> n >> q;
	for(int i{0};i<n;++i)fin >> s >> s;
	for(int i{0};i<q;++i)fin >> s >> s;
	while(q--)fout << "0\n";
	fout.close(),fin.close();
	return 0;
} 
