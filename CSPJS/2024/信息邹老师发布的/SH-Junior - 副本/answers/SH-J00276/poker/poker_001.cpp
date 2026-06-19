#include<bits/stdc++.h>
using namespace std;
char c[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,s=0;
	cin>>n;
	for(int i=0;i<n;i++){
		char a,b;
		int x,y;
		cin>>a>>b;
		
		if(a=='D'){
			x=1;
		}
		else if(a=='C'){
			x=2;
		}
		else if(a=='H'){
			x=3;
		}
		else if(a=='S'){
			x=4;
		}
		
		if(b=='A'){
			y=1;
		}
		else if(b=='2'){
			y=2;
		}
		else if(b=='3'){
			y=3;
		}
		else if(b=='4'){
			y=4;
		}
		else if(b=='5'){
			y=5;
		}
		else if(b=='6'){
			y=6;
		}
		else if(b=='7'){
			y=7;
		}
		else if(b=='8'){
			y=8;
		}
		else if(b=='9'){
			y=9;
		}
		else if(b=='T'){
			y=10;
		}
		else if(b=='J'){
			y=11;
		}
		else if(b=='Q'){
			y=12;
		}
		else if(b=='K'){
			y=13;
		}
		
		c[x][y]++;
	}
	for(int i=1;i<5;i++){
		for(int j=1;j<14;j++){
			if(c[i][j]==0){
				s++;
			}
		}
	}
	cout<<s;
	return 0;
}
