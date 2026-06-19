#include<bits/stdc++.h>
using namespace std;
#define N 1005//ÉèÖÃ´óÐ¡

int hp[10][20];

int changeC(char a){
	if(a=='D') return 1;
	else if(a=='C') return 2;
	else if(a=='H') return 3;
	else return 4;
}

int changeN(char a){
	if(a>='2'&&a<='9') return a-'0';
	else if(a=='A') return 1;
	else if(a=='T') return 10;
	else if(a=='J') return 11;
	else if(a=='Q') return 12;
	else return 13;
}

int change(string s){
	int tp=changeC(s[0]),nm=changeN(s[1]);
	hp[tp][nm]++;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	int n,ct=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		change(s);
	}
	for(int i=1;i<=4;++i) for(int j=1;j<=13;++j) if(hp[i][j]==0) ct++;
	cout<<ct;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


