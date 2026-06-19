#include<bits/stdc++.h>
using namespace std;
bool m[5][20]={};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		int g=0;
		if(a=='D')g=1;
		if(a=='C')g=2;
		if(a=='H')g=3;
		if(a=='S')g=4;
		if('0'<=b&&b<='9')m[g][b-'0']=1;
		if(b=='A')m[g][1]=1;
		if(b=='T')m[g][10]=1;
		if(b=='J')m[g][11]=1;
		if(b=='Q')m[g][12]=1;
		if(b=='K')m[g][13]=1;
	}
	int ct=52;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(m[i][j])ct--;
		}
	}
	cout<<ct;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
