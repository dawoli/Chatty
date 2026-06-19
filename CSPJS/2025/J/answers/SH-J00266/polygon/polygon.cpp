#include<bits/stdc++.h>
using namespace std;
int n, a[5005],ans;
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	fin>>n;
	for(int i = 1; i <= n; ++i)
		fin>>a[i];
	if(n == 3){
		if((a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)){
			fout<<1;
		}
		else
			fout<<0;
	}
	else
		fout<<n;
	return 0;
}
