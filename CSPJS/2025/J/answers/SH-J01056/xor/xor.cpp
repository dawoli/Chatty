#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int n;
	fin>>n;
	int N=n+5;
	int a[N]={0};
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	fout<<n;
	return 0;
}
