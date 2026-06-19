#include <bits/stdc++.h>
using namespace std;
bool poker[5][14];

int main(){
	freopen("poker.in","r", stdin);
	freopen("poker.out", "w", stdout); 
	int n;cin>>n;
	for (int i = 0;i < n;i++){
		string st;
		cin>>st;
		int sta = 0;
		if(st[0]=='S'){
			sta = 0;
		}
		if(st[0]=='H'){
			sta = 1;
		}
		if(st[0]=='C'){
			sta = 2;
		}
		if(st[0]=='S'){
			sta = 3;
		}
		char num = st[1];
		int n = int(num)-48;
		if(num=='A')n = 1;
		if(num=='T')n = 10;
		if(num=='J')n = 11;
		if(num=='Q')n = 12;
		if(num=='K')n = 13;
		poker[sta][n] = true;
	}
	int num = 52;
	for (int i = 0;i < 4;i++){
		for (int j = 1; j < 14; j++){
			if(poker[i][j]==true){
				num--;
			}
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
