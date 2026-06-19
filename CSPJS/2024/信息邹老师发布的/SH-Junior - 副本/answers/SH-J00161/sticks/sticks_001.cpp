#include<bits/stdc++.h>
//#define fin std::cin
//#define fout std::cout
//DELETE!!DELETE!!FILE!!FILE!!
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::string;
ifstream fin("sticks.in");
ofstream fout("sticks.out");
const int sticks[10]={6,2,5,5,4,5,6,3,7,6};
const int dabiao[51]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,202,200,208,608,808,888,1088,1888,2008,2888,6888,8888,10888,};
int minsticks(int stick){
	if(stick<2) return -1;
	else if(stick==2) return 1;
	else if(stick==3) return 7;
	else if(stick==4) return 4;
	else if(stick==5) return 2;
	else if(stick==6) return 0;
	else if(stick==7) return 8;
	else return -1;
}
int minsticks0(int stick){
	if(stick<2) return -1;
	else if(stick==2) return 1;
	else if(stick==3) return 7;
	else if(stick==4) return 4;
	else if(stick==5) return 2;
	else if(stick==6) return 6;
	else if(stick==7) return 8;
	else return -1;
}
int solve(int x){
	if(x<=7) return minsticks0(x);
}
int pow(int r,int p){
	int ret=1;
	for(int i=0;i<p;i++) ret*=r;
	return ret;
}
string sel(int x){
	string ret="";
	if(x%7==0){
		for(int i=0;i<x/7;i++){
			ret+='8';
		}
		return ret;
	}
	else if(x%7==1){
		ret+="10";
		for(int i=0;i<x/7-1;i++){
			ret+='8';
		}
	}
	else if(x<=50) ret=to_string(dabiao[x]);
	else {
		fout<<"1";
	}
}
int main(){
	int T;
	fin>>T;
	for(int i=0;i<T;i++){
		int n;
		fin>>n;
		fout<<sel(n)<<"\n";
	}
	return 0;
}
