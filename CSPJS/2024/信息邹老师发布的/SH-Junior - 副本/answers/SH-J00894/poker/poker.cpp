#include<bits/stdc++.h>
using namespace std;
ifstream fin("poker.in");
ofstream fout("poker.out");
set<string> a;
int main()
{
	int n;
	fin>>n;
	for(int i=0;i<n;++i)
	{
		string s;
		fin>>s;
		a.insert(s);
	}
	int len=a.size();
	int need=52-len;
	fout<<need<<endl;
	return 0;
}
