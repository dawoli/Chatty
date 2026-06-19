#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("employ.in");
ofstream fout("employ.out");
int mod=998244353;
int main(){
	long long n;
	fin>>n;
	long long m;
	fin>>m;
	string s;
	fin>>s;
	long long a[5100];
	long long k=0;
	
	for(int i=0; i<=n-1; i++){
		fin>>a[i];
		
		if(k>=a[i]){
			k++;
		
		}
		
		
	}
	
	unsigned long long ans=1;
	for(int i=1; i<=n-k; i++){
		ans%=mod;
		ans*=i;
	}
	fout<<ans%mod;
	return 0;
}
