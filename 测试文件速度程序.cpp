//测试文件速度程序
#include <fstream>
#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std; char s [ 10000005 ] ;
int x [ 10000005 ] ;
void testFstream(string fname, int N)
{
	ifstream fin ( fname.c_str()) ; 
	fin>>N;
	for(int i=0;i<N;i++) fin >>x[i];
	fin . close ( ) ;
}
void testFstream_str (string fname, int N) 
{
	ifstream fin(fname.c_str()); 
	//fout <<N<<endl;
	fin >> s;
	fin.close();
}
int main ( )
{
	//cerr(CLOCKS_PER_SEC); srand ( time ( 0 ) ) ;
	int st,et;
	
	st=clock();
	testFstream("d1.in",100000); 
	et = clock ( ) ;
	cout <<"10^5 integer:"<<et-st<<endl; 
	
	st=clock();
	testFstream("d2.in",1000000); 
	et = clock ( ) ;
	cout <<"10^6 integer:"<<et-st<<endl; 
	
	st=clock();
	testFstream("d3.in",10000000); 
	et = clock();
	cout <<"10^7 integer:"<<et-st<<endl; 
	
	st=clock();
	testFstream_str("d4.in",10000000); 
	et = clock ( ) ;
	cout <<"10^7 char:"<<et-st<<endl; 
	system("pause");
	return 0;
}
