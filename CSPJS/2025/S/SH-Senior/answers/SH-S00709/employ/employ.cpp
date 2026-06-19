#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
const long long mod=998244353;
int c[505];
int main(){
	int n,m;
	fin>>n>>m;
	string s;
	fin>>s;
	for(int i=0;i<n;i++){
		fin>>c[i];
	}
	long long ans=1;
	for(long long i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	fout<<ans;
}
