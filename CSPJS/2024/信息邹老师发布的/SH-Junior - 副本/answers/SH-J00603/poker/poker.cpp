#include<bits/stdc++.h>
using namespace std;
int cz[225],cz2[225],n,ct=52;
bool you[5][15];
void init(){
	cz['A']=1;
	cz['T']=10;
	cz['J']=11;
	cz['Q']=12;
	cz['K']=13;
	for(int i=2;i<=9;i++){
		cz['0'+i]=i;
	}
	cz2['D']=1;
	cz2['C']=2;
	cz2['H']=3;
	cz2['S']=4; 
}
int main(){
	cin.tie(nullptr);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	init();
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(you[cz2[s[0]]][cz[s[1]]]==false){
			ct--;
			you[cz2[s[0]]][cz[s[1]]]=true;
		}
	}
	cout<<ct;
	cout.flush();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
