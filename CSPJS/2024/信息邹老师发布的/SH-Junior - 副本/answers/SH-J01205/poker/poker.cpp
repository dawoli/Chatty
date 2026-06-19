#include<bits/stdc++.h>
using namespace std;
bool poker[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int x,number,sumcard=0;
	string card;
	cin>>x;
	for(int i=0;i<x;i++){
		cin>>card;
		if(card[1]=='T') number=10;
		else if(card[1]=='J') number=11;
		else if(card[1]=='Q') number=12;
		else if(card[1]=='K') number=13;
		else if(card[1]=='A') number=1;
		else number=card[1]-'0';
		if(card[0]=='D') poker[number]=1;
		else if(card[0]=='C') poker[number+13]=1;
		else if(card[0]=='H') poker[number+26]=1;
		else if(card[0]=='S') poker[number+39]=1;
	}for(int i=1;i<=52;i++) if(poker[i]) sumcard++;
	cout<<52-sumcard;
	return 0;
}
