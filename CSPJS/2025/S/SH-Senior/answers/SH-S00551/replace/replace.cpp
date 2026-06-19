#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("replace.in");
ofstream fout("replace.out");

int main(){
	long long a,b;
	fin>>a>>b;
	for(int i=1; i<=b; i++){
		fout<<0<<endl;
	}
	return 0;
}
