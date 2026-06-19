#include<iostream>
using namespace std;
int n;
string s;
int pok[10][60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>s;
		if(s[0]=='D'){
			int x=1;
			int y=0;
			if(s[1]=='A'){
				y=1;
			}else if(s[1]=='2'){
				y=2 ;
			}else if(s[1]=='3'){
				y=3;
			}else if(s[1]=='4'){
				y=4;
			}else if(s[1]=='5'){
				y=5;
			}else if(s[1]=='6'){
				y=6;
			}else if(s[1]=='7'){
				y=7;
			}else if(s[1]=='8'){
				y=8;
			}else if(s[1]=='9'){
				y=9;
			}else if(s[1]=='T'){
				y=10;
			}else if(s[1]=='J'){
				y=11;
			}else if(s[1]=='Q'){
				y=12;
			}else if(s[1]=='K'){
				y=13;
			}
			
			pok[x][y]=1;
		}
		if(s[0]=='C'){
			int x=2;
			int y=0;
			if(s[1]=='A'){
				y=1;
			}else if(s[1]=='2'){
				y=2 ;
			}else if(s[1]=='3'){
				y=3;
			}else if(s[1]=='4'){
				y=4;
			}else if(s[1]=='5'){
				y=5;
			}else if(s[1]=='6'){
				y=6;
			}else if(s[1]=='7'){
				y=7;
			}else if(s[1]=='8'){
				y=8;
			}else if(s[1]=='9'){
				y=9;
			}else if(s[1]=='T'){
				y=10;
			}else if(s[1]=='J'){
				y=11;
			}else if(s[1]=='Q'){
				y=12;
			}else if(s[1]=='K'){
				y=13;
			}
			
			pok[x][y]=1;
		}
		if(s[0]=='H'){
			int x=3;
			int y=0;
			if(s[1]=='A'){
				y=1;
			}else if(s[1]=='2'){
				y=2 ;
			}else if(s[1]=='3'){
				y=3;
			}else if(s[1]=='4'){
				y=4;
			}else if(s[1]=='5'){
				y=5;
			}else if(s[1]=='6'){
				y=6;
			}else if(s[1]=='7'){
				y=7;
			}else if(s[1]=='8'){
				y=8;
			}else if(s[1]=='9'){
				y=9;
			}else if(s[1]=='T'){
				y=10;
			}else if(s[1]=='J'){
				y=11;
			}else if(s[1]=='Q'){
				y=12;
			}else if(s[1]=='K'){
				y=13;
			}
			
			pok[x][y]=1;
		}
		if(s[0]=='S'){
			int x=4;
			int y=0;
			if(s[1]=='A'){
				y=1;
			}else if(s[1]=='2'){
				y=2 ;
			}else if(s[1]=='3'){
				y=3;
			}else if(s[1]=='4'){
				y=4;
			}else if(s[1]=='5'){
				y=5;
			}else if(s[1]=='6'){
				y=6;
			}else if(s[1]=='7'){
				y=7;
			}else if(s[1]=='8'){
				y=8;
			}else if(s[1]=='9'){
				y=9;
			}else if(s[1]=='T'){
				y=10;
			}else if(s[1]=='J'){
				y=11;
			}else if(s[1]=='Q'){
				y=12;
			}else if(s[1]=='K'){
				y=13;
			}
			
			pok[x][y]=1;
		}
	}
	int ans=52;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			
			if(pok[i][j]==1){
				ans--;
			}
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
