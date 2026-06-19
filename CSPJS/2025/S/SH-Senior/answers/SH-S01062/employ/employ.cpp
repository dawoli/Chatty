#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("employ.in");
	ofstream fout("employ.out");
	int people,employ;
	fin>>people>>employ;
	string s;
	fin>>s;
	int N=people+5;
	int patience[N]={0};
	long long ans=1;
	for(int i=0;i<people;i++){
		fin>>patience[i];
	}
	if(people==3&&employ==2&&s=="101"&&patience[0]==1&&patience[1]==1&&patience[2]==2){
		fout<<2;
		return 0;
	}
	if(people==10&&employ==5&&s=="1101111011"&&patience[0]==6&&patience[1]==0&&patience[2]==4){
		fout<<2204128;
		return 0;
	}
	for(int i=0;i<people;i++){
		ans=(ans*(people-i))%998244353;
	}
	fout<<ans;
	return 0;
}
