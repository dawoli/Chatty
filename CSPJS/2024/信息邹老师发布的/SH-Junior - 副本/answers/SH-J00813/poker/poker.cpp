#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	bool omega[4][13];
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			omega[i][j]=false;
		}
	} 
	for(int i=0;i<n;i++){
		string card;
		cin>>card;
		int prima,secunda;
		switch(card[0]){
			case 'D':
				prima=0;
				break;
			case 'C':
				prima=1;
				break;
			case 'H':
				prima=2;
				break;
			case 'S':
				prima=3;
				break;
		}
		switch(card[1]){
			case 'A':
				secunda=0;
				break;
			case '2':
				secunda=1;
				break;
			case '3':
				secunda=2;
				break;
			case '4':
				secunda=3;
				break;
			case '5':
				secunda=4;
				break;
			case '6':
				secunda=5;
				break;
			case '7':
				secunda=6;
				break;
			case '8':
				secunda=7;
				break;
			case '9':
				secunda=8;
				break;
			case 'T':
				secunda=9;
				break;
			case 'J':
				secunda=10;
				break;
			case 'Q':
				secunda=11;
				break;
			case 'K':
				secunda=12;
				break;
		}
		omega[prima][secunda]=true;
	}
	int sum=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(!omega[i][j])
			sum++;
		}
	} 
	cout<<sum<<endl;
	return 0; 
} 
