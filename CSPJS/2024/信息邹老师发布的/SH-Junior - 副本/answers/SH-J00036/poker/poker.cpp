#include<iostream>
#include<string>
//#include<stdc++.h>
using namespace std;
long long p[60][60];
int n,cnt;
string str1;
int way(char a){
	if(a=='A') return 1;
	if(a=='T') return 10;
	if(a=='J') return 11;
	if(a=='Q') return 12;
	if(a=='K') return 13;
}
int way1(char b){
	if(b=='D') return 1;
	if(b=='C') return 2;
	if(b=='H') return 3;
	if(b=='S') return 4;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str1;
		if(str1[1]>='2' && str1[1]<='9') p[way1(str1[0])][int(str1[1])-48]++;
		else  p[way1(str1[0])][way(str1[1])]++;
		
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(p[i][j]) cnt++;
		}
	}
	cout<<(52-cnt)<<endl;
	return 0;
}
