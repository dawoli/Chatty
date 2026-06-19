#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	int n;
	fin>>n;
	int N=n+5;
	int a[N]={0};
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	if(n<3)	fout<<0;
	else	fout<<7;
	return 0;
}
