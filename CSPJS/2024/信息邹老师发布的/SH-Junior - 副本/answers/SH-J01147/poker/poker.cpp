#include<bits/stdc++.h>
std::ifstream fin("poker.in");
std::ofstream fout("poker.out");
int n,S,Y,ans=52;
char s,y;
bool a[13][4];
int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>s;
		fin>>y;
		if(s=='D'){
			S=0;
		}
		else if(s=='C'){
			S=1;
		}
		else if(s=='H'){
			S=2;
		}
		else{
			S=3;
		}
		if(y=='A'){
			Y=0;
		}
		else if(y=='T'){
			Y=9;
		}
		else if(y=='J'){
		    Y=10;
		}
		else if(y=='Q'){
			Y=11;
		}
		else if(y=='K'){
			Y=12;
		}
		if(a[Y][S]){
			
		}
	}
	return 0;
}
