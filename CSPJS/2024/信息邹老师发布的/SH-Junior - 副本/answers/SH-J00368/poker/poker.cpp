#include<iostream>
#include<fstream>
using namespace std;
int s[52],n,ans;
int main(){
	ifstream fin("poker.in");
	fin>>n;
	for(int i=1;i<=n;++i){
		char a,b;
		fin>>a>>b;
		int j=-1;
		if(a=='C') j=12;
		if(a=='H') j=25;
		if(a=='S') j=38;
		if(b=='T') j+=10;
		else if(b=='J') j+=11;
		else if(b=='Q') j+=12;
		else if(b=='K') j+=13;
		else if(b=='A') j+=1;
		else j+=b-'0';
		s[j]++;
	}
	for(int i=0;i<52;++i){
		if(s[i] == 0) ++ans;
	}
	ofstream fout("poker.out");
	fout<<ans<<endl;
	return 0;
}
