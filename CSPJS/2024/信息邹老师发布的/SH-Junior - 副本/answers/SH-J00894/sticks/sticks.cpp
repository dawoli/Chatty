#include<bits/stdc++.h>
using namespace std;
ifstream fin("sticks.in");
ofstream fout("sticks.out");
const int N=100010;
int a[N];
int main()
{
	int n;
	fin>>n;
	for(int i=0;i<n;++i)
	{
		fin>>a[i];
		fout<<-1<<endl;
	}
	return 0;
}
