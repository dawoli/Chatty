#include<iostream>
#include<cstdio>
using namespace std;
bool k[5][14];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for(int m = 1; m <= n; m++){
		char a, b;
		int i, j;
		cin >> a >> b;
		if(a=='D')i = 1;
		if(a == 'C') i = 2;
		if(a=='H')i=3;
		if(a=='S')i = 4;
		if(isdigit(b))j = b-48;
		if(b=='A')j = 1;
		if(b == 'T')j = 10;
		if(b == 'J')j = 11;
		if(b =='Q')j=12;
		if(b =='K')j=13;
		k[i][j] = 1;
		
	}
	int res = 0;	 
	for(int i =1; i <= 4; i++){
		for(int j =1; j <= 13; j++){
			
			if(!k[i][j])res++;
		}
		
	}
	cout << res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
