#include<bits/stdc++.h>
//#define fin std::cin
//#define fout std::cout
//DELETE!!DELETE!!FILE!!FILE!!
using std::ifstream;
using std::ofstream;
using std::cerr;
ifstream fin("poker.in");
ofstream fout("poker.out");
bool pokers[13][4];
int n;
int ans=0;
int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		char number,color;
		fin>>color>>number;
		if(number=='A'){
			int num=0;
			if(color=='D') pokers[num][0]=true;
			else if(color=='C') pokers[num][1]=true;
			else if(color=='H') pokers[num][2]=true;
			else pokers[num][3]=true;
		}
		else if('2'<=number and number<='9'){
			int num=number-'0'-1;
			if(color=='D') pokers[num][0]=true;
			else if(color=='C') pokers[num][1]=true;
			else if(color=='H') pokers[num][2]=true;
			else pokers[num][3]=true;
		}
		else {
			int num;
			if(number=='T') num=9;
			else if(number=='J') num=10;
			else if(number=='Q') num=11;
			else num=12;
			;
			if(color=='D') pokers[num][0]=true;
			else if(color=='C') pokers[num][1]=true;
			else if(color=='H') pokers[num][2]=true;
			else pokers[num][3]=true;
		}
	}
	for(int i=0;i<13;i++){
		for(int j=0;j<4;j++){
			if(!pokers[i][j]){
				ans++;
				//cerr<<"i="<<i<<",j="<<j<<"\n";
			}
		}
	}
	fout<<ans;
	return 0;
}
