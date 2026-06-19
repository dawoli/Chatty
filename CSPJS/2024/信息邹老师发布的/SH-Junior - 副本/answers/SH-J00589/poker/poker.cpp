#include <bits/stdc++.h>
using namespace std;
bool tag[100][100];
int ans=0;
int szpd(char ch){
	switch(ch){
		case 'A':return 1;
		case '2':return 2;
		case '3':return 3;
		case '4':return 4;
		case '5':return 5;
		case '6':return 6;
		case '7':return 7;
		case '8':return 8;
		case '9':return 9;
		case 'T':return 10;
		case 'J':return 11;
		case 'Q':return 12;
		case 'K':return 13;
	}
}
int hspd(char ch){
	switch(ch){
		case 'D':return 1;
		case 'C':return 2;
		case 'H':return 3;
		case 'S':return 4;
	}
}

int main(){
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			tag[i][j]=0;
		}
	}
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	//rp++
	//akioi
	int n;
	char p1,p2;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p1 >> p2;
		int hs=hspd(p1);
		int sz=szpd(p2);
		if(!tag[hs][sz]){
			ans++;
			tag[hs][sz]=1; 
		}		
	}
	cout << 52-ans;
	return 0;
} 
